#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define mp make_pair
#define INF 0x3fffffff
#define MAXN 100001
int T,N,M,a[7],cnt[MAXN],ans=INF;Pair b[6*MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	For(i,1,6)a[i]=get();N=get();For(i,1,N){int x=get();For(j,1,6)b[(i-1)*6+j]=mp(x-a[j],i);}sort(b+1,b+N*6+1);
	int j=0,tot=0;For(i,1,N*6){while(j<N*6&&tot<N)cnt[b[++j].second]++,cnt[b[j].second]==1?tot++:0;if(tot==N)ans=min(ans,b[j].first-b[i].first);cnt[b[i].second]--;if(!cnt[b[i].second])tot--;}cout<<ans<<endl;return 0;
}