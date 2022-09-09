#include<cstdio>
#include<cstring>
#include<iostream>
typedef long long ll;
const int MAXN = 2e5 + 5;
using namespace std;

char s[MAXN];
int t[MAXN];
int nxt[MAXN];

inline void solve(void)
{
	int n;
	ll a,b;
	cin>>n>>a>>b;
	scanf("%s",s+1);
	for(int i=1; i<=n+1; ++i) t[i]=0;
	for(int i=1; i<=n; ++i)
		if(s[i]=='1') t[i]=t[i+1]=1;
	
	for(int i=0; i<=n+1;)
	{
		int tmp=i;
		do ++i; while(!t[i] && i<=n+1);
		nxt[tmp]=i;
	}
	//for(int i=0; i<=n+1; ++i) printf("nxt[%d]: %d\n",i,nxt[i]);
	ll ans = n*a + (n+1)*b;
	for(int i=nxt[0]; i<=n+1; i=nxt[i])
	{
		ans += b;
		if(nxt[i]>n+1) ans+=a;
		else ans += min(a*2, b*(nxt[i]-i-1));
	}
	if(nxt[0]<=n+1) ans+=a;
	cout<<ans<<endl;
}

int main(void)
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}