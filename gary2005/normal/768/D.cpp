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
double dp[7500][1001];
int main(){
	fastio;
	double k,q;
	cin>>k>>q;
	dp[0][0]=1;
	rb(i,1,7500-1){
		rb(j,1,k){
			dp[i][j]=(dp[i-1][j]*(double)(j)+dp[i-1][j-1]*(double )(k-j+1))/k;
		}
	}
	const double eps=1e-7;
	rb(i,1,q){
		int a;
		cin>>a;
		int l=1,r=7500-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(dp[mid][int(k)]*2000.0>=(double)a-eps){
				r=mid;
			}
			else l=mid+1;
		}
		cout<<l<<endl;
	}
	return 0;
}