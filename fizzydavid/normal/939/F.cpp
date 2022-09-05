//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
int n;
int dp[2][100111],ndp[2][100111];
int mnp[100111],mns[100111];
void go0(int l)
{
	memset(ndp,31,sizeof(ndp));
	for(int i=0;i<=n;i++)ndp[0][i]=dp[0][i];
	for(int i=l;i<=n;i++)ndp[1][i]=dp[1][i-l];
	swap(dp,ndp);
}
void upd(int &x,int v){x=v<x?v:x;}
void init(int a[],int k)
{
	for(int i=0;i<=n;i++)mnp[i]=i%k==0?a[i]:min(mnp[i-1],a[i]);
	for(int i=n;i>=0;i--)mns[i]=i%k==0||i==n?a[i]:min(mns[i+1],a[i]);
}
void go1(int l)
{
	memset(ndp,31,sizeof(ndp));
	for(int i=0;i<=n;i++)ndp[0][i]=dp[0][i];
	for(int i=l;i<=n;i++)ndp[1][i]=dp[1][i-l];
	init(dp[0],l+1);
	for(int i=0;i<=n;i++)upd(ndp[1][i],(i<=l?mnp[i]:min(mns[i-l],mnp[i]))+1);
	init(dp[1],l+1);
	for(int i=0;i<=n;i++)upd(ndp[0][i],(i<=l?mnp[i]:min(mns[i-l],mnp[i]))+1);
	swap(dp,ndp);
	for(int i=0;i<=n;i++)upd(dp[0][i],dp[1][i]+1),upd(dp[1][i],dp[0][i]+1);
}
int main()
{
	int k;
	cin>>n>>k;
	memset(dp,31,sizeof(dp));
	dp[0][0]=dp[1][0]=0;
	int CurT=0;
	for(int i=1;i<=k;i++)
	{
		int l,r;
		cin>>l>>r;
		go0(l-CurT);
		go1(r-l);
		CurT=r;
//		for(int j=0;j<=n;j++)cerr<<dp[0][j]<<" ";cerr<<endl;
//		for(int j=0;j<=n;j++)cerr<<dp[1][j]<<" ";cerr<<endl;
//		cerr<<endl;
	}
	go0(2*n-CurT);
	int ans=min(dp[0][n],dp[1][n]);
	if(ans<=2*n)cout<<"Full"<<endl<<ans<<endl;
	else cout<<"Hungry"<<endl;
	return 0;
}