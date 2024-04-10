#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define Pair pair<int,int>
#define mp make_pair
#define MAXN 200001
int N,a[MAXN];ll sum[MAXN],ans;map<Pair,int>vis;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get();For(i,1,N)sum[i]=sum[i-1]+(a[i]=get());For(i,1,N-2){int t=1;while(t<=a[i])t<<=1;For(j,i+2,N)if((a[i]^a[j])==sum[j-1]-sum[i])ans++,vis[mp(i,j)]=1;else if(sum[j-1]-sum[i]>=t)break;}
	FOR(i,N,3){int t=1;while(t<=a[i])t<<=1;FOR(j,i-2,1)if(!vis[mp(j,i)]&&(a[i]^a[j])==sum[i-1]-sum[j])ans++;else if(sum[i-1]-sum[j]>=t)break;}cout<<ans<<endl;return 0;
}