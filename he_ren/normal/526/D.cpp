#include<cstdio>
#include<cstdlib>
#include<ctime>
typedef long long ll;
const int MAXN = 1e6 + 5;

inline int min(int a,int b){ return a<b? a: b;}

char s[MAXN];
struct Hash_map
{
	int mod,base,pb[MAXN];
	int h[MAXN];
	
	inline void init(int n)
	{
		pb[0]=1;
		for(int i=1; i<=n; ++i)
		{
			pb[i] = ((ll)pb[i-1] * base) %mod;
			h[i] = ((ll)h[i-1]*base + s[i]) %mod;
		}
	}
	
	inline int val(int l,int r)
	{
		int res = (h[r] - (ll)h[l-1]*pb[r-l+1]) %mod; 
		return res<0? res+mod: res;
	}
	
	inline bool check(int l2,int len){ return h[len] == val(l2,l2+len-1);}
}m1,m2;

int ans[MAXN];

int main(void)
{
	srand(time(0));
	int n,p;
	scanf("%d%d%s",&n,&p,s+1);
	
	m1.mod=19260817; m1.base = rand()%233 + 321; m1.init(n);
	m2.mod=19491001; m2.base = rand()%321 + 233; m2.init(n);
	
	int maxl = n/p;
	for(int l=1; l<=maxl; ++l)
	{
		int v1 = m1.h[l], v2 = m2.h[l];
		bool flag=1;
		for(int i=1; i<p; ++i)
			if(v1 != m1.val(i*l+1, (i+1)*l) || v2 != m2.val(i*l+1, (i+1)*l))
			{
				flag=0;
				break;
			}
		if(!flag) continue;
		
		int L=0, R=min(l,n-p*l);
		int pl = p*l + 1;
		while(L<R)
		{
			int mid = (L+R+1)>>1;
			if(m1.check(pl, mid) && m2.check(pl, mid)) L = mid;
			else R = mid-1;
		}
		
		++ans[pl-1];
		--ans[pl+L];
	}
	
	int cnt=0;
	for(int i=1; i<=n; ++i)
	{
		cnt+=ans[i];
		if(cnt>0) putchar('1');
		else putchar('0');
	}
	return 0;
}