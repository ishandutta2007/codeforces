//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const LL INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,d;
LL dp[2][150000+5];
int a[300+5],b[300+5],T[300+5];
LL res=0;
int deq[5000000+5];
int h=1,t=0;
int main(){
	memset(dp,127,sizeof(dp));
	cin>>n>>m>>d;
	rep(i,m)
		cin>>a[i+1]>>b[i+1]>>T[i+1],res+=b[i+1];
	rep(i,n)
		dp[1][i+1]=abs(a[1]-(i+1));
	int las=1,now=0;
	rb(i,2,m)		
	{
		LL td= (LL)(T[i]-T[i-1])*(LL)(d);
		memset(deq,0,sizeof(deq));
		h=1;
		t=0;
		rb(i,1,int(min((LL)(n),td))){
			while(t>=h&&dp[las][deq[t]]>=dp[las][i]) {
//			if(n==1000) cout<<t<<endl;
			t--;
			}
			deq[++t]=i;
		}
		rb(j,1,n)
		{
			if(j+td<=n)
			{
				int nex=j+td;
				while(t>=h&&dp[las][deq[t]]>=dp[las][nex]) t--;
				deq[++t]=nex;
			}
			while(deq[h]<j-td) h++;
			dp[now][j]=dp[las][deq[h]];
			dp[now][j]+=abs(a[i]-j);
		}
		swap(las,now);
	}
	LL mini=INF*100000000;
	rb(i,1,n)
		mini=min(mini,dp[las][i]);
	cout<<res-mini<<endl;
	return 0;
}