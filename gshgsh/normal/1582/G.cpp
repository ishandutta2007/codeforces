#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,K,a[MAXN],l[MAXN],tot,prm[MAXN],mn[MAXN],st[MAXN][20],lg2[MAXN];vector<int>sta[MAXN];bool Not[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void insert(int x,int p){l[p]=p;while(x>1)sta[mn[x]].push_back(p),x/=mn[x];}
void erase(int x,int p){l[p]=p;while(x>1){if(sta[mn[x]].empty()){l[p]=0;return;}l[p]=min(l[p],sta[mn[x]].back());sta[mn[x]].pop_back();x/=mn[x];}}
int ask(int l,int r){int k=lg2[r-l+1];return min(st[l][k],st[r-(1<<k)+1][k]);}
int main()
{
	N=get();For(i,1,N)K=max(K,a[i]=get());For(i,2,K){if(!Not[i])prm[++tot]=i,mn[i]=i;for(int j=1;j<=tot&&i*prm[j]<=K;j++){Not[i*prm[j]]=1;mn[i*prm[j]]=prm[j];if(i%prm[j]==0)break;}}
	string s;cin>>s;For(i,1,N)if(s[i-1]=='*')insert(a[i],i);else erase(a[i],i);
	For(i,2,N)lg2[i]=lg2[i>>1]+1;For(i,1,N)st[i][0]=l[i];for(int j=1;1<<j<=N;j++)For(i,1,N-(1<<j)+1)st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	ll ans=0;For(i,1,N){int l=i,r=N,pos=i-1;while(l<=r){int mid=l+r>>1;ask(i,mid)>=i?pos=mid,l=mid+1:r=mid-1;}ans+=pos-i+1;}cout<<ans<<'\n';return 0;
}