#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define INF 0x3fffffff
#define MAXN 512
int N,M,cnt[MAXN],mn[MAXN],mn2[MAXN],id[MAXN],id2[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,0,MAXN-1)mn[i]=mn2[i]=INF;For(i,1,N){int k=get(),x=0;while(k--)x|=1<<get()-1;for(int j=x;j<MAXN;j=x|j+1)cnt[j]++;}
	For(i,1,M){int c=get(),k=get(),x=0;while(k--)x|=1<<get()-1;if(c<mn[x])id2[x]=id[x],mn2[x]=mn[x],id[x]=i,mn[x]=c;else if(mn2[x]>c)id2[x]=i,mn2[x]=c;}
	int ans=-1,x=-1,y=-1;For(i,0,MAXN-1)if(mn[i]!=INF)For(j,i+1,MAXN-1)if(mn[j]!=INF)if(cnt[i|j]>ans)ans=cnt[i|j],x=i,y=j;else if(cnt[i|j]==ans&&mn[i]+mn[j]<mn[x]+mn[y])x=i,y=j;
	For(i,0,MAXN-1)if(mn2[i]!=INF)if(cnt[i]>ans||(cnt[i]==ans&&mn[i]+mn2[i]<mn[x]+(x==y?mn2[y]:mn[y])))ans=cnt[i],x=y=i;if(x==y)cout<<id[x]<<' '<<id2[x]<<'\n';else cout<<id[x]<<' '<<id[y]<<'\n';return 0;
}