#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 2000001
int N,a[MAXN],f[MAXN];pair<int,int>v[MAXN];
int getc(){char c=getchar();while(c!='0'&&c!='1'&&c!='?')c=getchar();return c=='0'?0:c=='1'?1:2;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int main()
{
	cin>>N;For(i,1,N)a[i]=getc();int cnt[3]={0,0,0},r=N;FOR(i,N,1){cnt[a[i]]++;while(cnt[0]&&cnt[1])cnt[a[r--]]--;v[i]={r-i+1,i};}sort(v+1,v+N+1);
	For(i,1,N+1)f[i]=i;int j=1;For(i,1,N){while(j<=N&&v[j].first<i)f[v[j].second]=v[j].second+1,j++;int x=getf(1),ans=0;while(x<=N)ans++,x=getf(x+i);cout<<ans<<" \n"[i==N];}
}