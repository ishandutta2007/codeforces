#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 18 + 5;
const int ALL = (1<<10) + 5;
const int all = (1<<10)-1;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int pw10[MAXN];
int tot[ALL];
#define lowbit(x) ((x)&-(x))

int n,d;
char s[MAXN];
pii f[MAXN][ALL];
bool vis[MAXN][ALL];
pii gao(int pos,int mask,bool lead,bool lim)
{
	if(pos>n) return Mp(1,0);
	if(vis[pos][mask] && !lead && !lim) return f[pos][mask];
	
	pii res=Mp(0,0);
	int up = lim?s[pos]:9;
	for(int i=0; i<=up; ++i)
	{
		int now = (lead&&!i)? 0: (mask|(1<<i));
		if(tot[now]>d) continue;
		pii tmp = gao(pos+1,now,lead&&!i,lim&&i==up);
		add_mod(res.fir, tmp.fir);
		add_mod(res.sec, ((ll)tmp.fir*i*pw10[n-pos] + tmp.sec) %mod);
	}
	if(!lim && !lead)
		f[pos][mask]=res, vis[pos][mask]=1;
	return res;
}

int calc(ll x)
{
	memset(vis,0,sizeof(vis));
	
	sprintf(s+1,"%lld",x);
	n=strlen(s+1);
	for(int i=1; i<=n; ++i) s[i]-='0';
	
	return gao(1,0,1,1).sec;
}

int main(void)
{
	pw10[0]=1;
	for(int i=1; i<MAXN; ++i) pw10[i] = (ll)pw10[i-1]*10 %mod;
	tot[0]=0;
	for(int i=1; i<ALL; ++i) tot[i]=tot[i^lowbit(i)]+1;
	
	ll l,r;
	scanf("%lld%lld%d",&l,&r,&d);
	int ans = calc(r)-calc(l-1);
	printf("%d",(ans%mod+mod)%mod);
	return 0;
}