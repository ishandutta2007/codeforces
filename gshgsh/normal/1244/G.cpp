#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,ans[MAXN],p1[MAXN],p2[MAXN],cnt[MAXN];ll K,sum;bool vis1[MAXN],vis2[MAXN];
int main()
{
	cin>>N>>K;if(K<1ll*N*(N+1)/2){cout<<-1<<endl;return 0;}int x=N;For(i,1,N){while(cnt[x]==2||K-x<1ll*(N-i)*(N-i+1)/2)x--;ans[i]=x;cnt[x]++;K-=x;}
	For(i,1,N)(i&1?vis1:vis2)[(i&1?p1:p2)[i]=ans[i]]=1;int y1=1,y2=1;FOR(i,N,1)if(i&1){while(vis2[y2])y2++;p2[i]=y2++;}else{while(vis1[y1])y1++;p1[i]=y1++;}
	For(i,1,N)sum+=max(p1[i],p2[i]);cout<<sum<<endl;For(i,1,N)cout<<p1[i]<<' ';cout<<endl;For(i,1,N)cout<<p2[i]<<' ';cout<<endl;return 0;
}