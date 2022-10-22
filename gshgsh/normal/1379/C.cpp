#include<algorithm>
#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define Thair pair<int,Pair>
#define mp make_pair
#define F first
#define S second
#define MAXN 100001
int T,N,M,a[MAXN][2],pre[MAXN];bool vis[MAXN];Thair b[MAXN*2];
ll calc(int x,int lft)
{
	if(x>2*N||lft<=0)return 0;if(!b[x].S.S)return !pre[b[x].S.F]?vis[b[x].S.F]=1,b[x].F+calc(x+1,lft-1):b[x].F+1ll*b[pre[b[x].S.F]].F*(lft-1);
	return !vis[b[x].S.F]?pre[b[x].S.F]=x,max(a[b[x].S.F][0]+1ll*a[b[x].S.F][1]*(lft-1),calc(x+1,lft)):1ll*b[x].F*lft;
}
int main(){cin>>T;while(T--){cin>>M>>N;For(i,1,N)cin>>a[i][0]>>a[i][1],pre[i]=vis[i]=0,b[i*2-1]=mp(a[i][0],mp(i,0)),b[i*2]=mp(a[i][1],mp(i,1));sort(b+1,b+N*2+1,greater<Thair>());cout<<calc(1,M)<<endl;}return 0;}