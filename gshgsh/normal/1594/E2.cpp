#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 2001
#define MAXM 61
int N,M,f[MAXN*MAXM][6];ll a[MAXN*MAXM];map<ll,int>val,vis;
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int solve(int x,int c)
{
	if(val[a[x]]&&val[a[x]]-1!=c)return 0;if(f[x][c]!=-1)return f[x][c];
	ll sum[2]={0,0};For(y,0,1){if(!vis[a[x]<<1|y]){sum[y]=1;continue;}For(j,0,5)if(c!=j&&((c^j)!=1))sum[y]=(sum[y]+solve(vis[a[x]<<1|y],j))%P;}return f[x][c]=1ll*sum[0]*sum[1]%P;
}
int main()
{
	cin>>M>>N;For(i,1,N){string s;cin>>a[i]>>s;val[a[i]]=s[0]=='w'?1:s[0]=='y'?2:s[0]=='g'?3:s[0]=='b'?4:s[0]=='r'?5:6;}
	int tot=N;For(i,1,N){ll x=a[i];while(x>1)a[++tot]=x>>=1;}sort(a+1,a+tot+1);tot=unique(a+1,a+tot+1)-a-1;For(i,1,tot)vis[a[i]]=i;
	memset(f,-1,sizeof(f));int ans=0;For(i,0,5)ans=(ans+solve(1,i))%P;cout<<1ll*ans*pow(4,((1ll<<M)-1-tot)%(P-1))%P<<'\n';return 0;
}