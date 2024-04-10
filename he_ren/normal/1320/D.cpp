#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

struct Hash
{
	int base, pw[MAXN], h[MAXN];
	Hash(void)
	{
		base = rand() %mod + 114514;
		pw[0] = 1;
		for(int i=1; i<MAXN; ++i)
			pw[i] = (ll)pw[i-1] * base %mod;
	}
	
	void build(char s[])
	{
		for(int i=1; s[i]; ++i)
			h[i] = ((ll)h[i-1] * base + s[i]) %mod;
	}
	
	inline int query(int l,int r)
	{
		return (h[r] + mod - (ll)h[l] * pw[r-l] %mod) %mod;
	}
	
	inline int connect(int x,int y,int yl){ return ((ll)x * pw[yl] + y) %mod;}
}h[2];

char s[MAXN], t[MAXN];
int to[MAXN], lst[MAXN], nxt[MAXN];

inline int calc(int l,int r,Hash &h)
{
	int L = nxt[l], R = lst[r];
	
	int res = h.query(to[L], to[R]);
	
	if((L-l)&1) res = h.connect('1', res, to[R]-to[L]+1);
	if((r-R)&1) res = h.connect(res, '1', 1);
	
	return res;
}

int main(void)
{
	srand(time(0));
	
	int n;
	scanf("%d%s",&n,s+1);
	
	int m=0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && s[i]==s[j]) ++j;
		if(s[i]=='1')
		{
			if((j-i)&1) t[++m]='1'; 
		}
		else
		{
			for(int k=i; k<j; ++k)
				t[++m]='0',
				to[k] = m;
		}
	}
	
	for(int i=1; i<=n; ++i)
		lst[i] = (s[i]=='0')? i: lst[i-1];
	
	nxt[n+1] = n+1;
	for(int i=n; i>=1; --i)
		nxt[i] = (s[i]=='0')? i: nxt[i+1];
	
	h[0].build(t);
	h[1].build(t);
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int l1,l2,len;
		scanf("%d%d%d",&l1,&l2,&len);
		int r1 = l1+len-1, r2 = l2+len-1;
		
		if(nxt[l1]>r1 || nxt[l2]>r2)
		{
			if((nxt[l1]>r1) != (nxt[l2]>r2)) printf("NO\n");
			else printf("YES\n");
			continue;
		}
		
		bool flag=1;
		for(int k=0; k<=1; ++k)
			if(calc(l1,r1,h[k]) != calc(l2,r2,h[k]))
			{
				flag=0;
				break;
			}
		
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}