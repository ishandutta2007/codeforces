/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,a[55][20000+2],k,sum[55][20000+2],dp[55][20000+2];int Max[20000+2][2];
int main(){
	fastio;
	/*
	Solution By Gary### 
	dp[i][j]iij
	dp[i][j]=MAX(dp[i-1][l]-)+sum(i,j,j+k-1)+sum(i+1,j,j+k-1);
	Total in O(n*m*m)
	k->O(k) 
	Total in O(n*m*k)
	*/
	cin>>n>>m>>k;
	rb(i,1,n)
		rb(j,1,m)
			cin>>a[i][j];
	rb(i,1,n){
		rb(j,1,k) sum[i][1]+=a[i][j];
		rb(j,2,m-k+1){
			sum[i][j]=sum[i][j-1];
			sum[i][j]-=a[i][j-1];
			sum[i][j]+=a[i][j+k-1];
		}
	}
	rb(j,1,m-k+1){
		dp[1][j]=sum[1][j]+sum[2][j];
	}
	
	rb(i,2,n){
		priority_queue<mp> q; 
		rb(j,1,m-k+1){
			Max[j][0]=max(Max[j-1][0],dp[i-1][j]);
		}
		rl(j,m-k+1,1){
			Max[j][1]=max(Max[j+1][1],dp[i-1][j]);
		}
		rb(j,1,m-k+1)
		{
			int l,r;
			l=j-k;
			r=j+k;
			if(l>=1){
				dp[i][j]=Max[l][0];
			}
			if(r<=m-k+1){
				dp[i][j]=max(dp[i][j],Max[r][1]);
			}
			dp[i][j]+=sum[i][j]+sum[i+1][j];
		}
		int minus_cover=0;
		rl(j,m-k+1,1){
			minus_cover+=a[i][j+k];
			q.push(II(dp[i-1][j]-minus_cover-sum[i][j],j));
			while(!q.empty()){
				if(q.top().SEC>=j+k) q.pop();
				else break;
			}
			if(!q.empty())
			dp[i][j]=max(dp[i][j],q.top().FIR+minus_cover+sum[i][j]+sum[i+1][j]);
		}
		while(!q.empty()) q.pop();
		minus_cover=0;
		rb(j,1,m-k+1){
			minus_cover+=a[i][j-1];
			q.push(II(dp[i-1][j]-minus_cover-sum[i][j],j));
			while(!q.empty()){
				if(q.top().SEC<=j-k) q.pop();
				else break;
			}
			if(!q.empty())
			dp[i][j]=max(dp[i][j],q.top().FIR+minus_cover+sum[i][j]+sum[i+1][j]);
		}
//		q.clear();
	}
//	cout<<dp[2][3]<<endl;
	int res=0;
	rb(i,1,m-k+1)
		res=max(res,dp[n][i]);
	cout<<res<<endl;
	return 0;
}