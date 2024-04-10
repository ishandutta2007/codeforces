/*
AuThOr Gwj
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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,k;
double sum[200000+2],inv[200000+2],s[200000+2],t[200000+2];
struct Line {
	double k,b;
};
bool bad(Line A,Line B,Line C){
	//return AB<AC
	/*
	A.k*x+A.b=B.k*x+B.b
	x=(B.b-A.b)/(A.k-B.k)
	*/
	return (B.b-A.b)*(A.k-C.k)<(C.b-A.b)*(A.k-B.k);
}
double getval(Line A,double x){
	return A.k*x+A.b;
}
double dp[2][200000+2];
int main(){
//	fastio;
	cin>>n>>k;
	rb(i,1,n)	cin>>t[i];
	rb(i,1,n) sum[i]=sum[i-1]+t[i];
	rb(i,1,n) s[i]=s[i-1]+sum[i]/t[i];
	rb(i,1,n) inv[i]=inv[i-1]+1.0/t[i];
	bool prev=1,now=0;
	rb(i,1,n)
		dp[prev][i]=s[i];
	rb(id,1,k-1){
		deque<Line> q;
		rb(i,id+1,n){
			Line tmp;
			tmp.b=dp[prev][i-1]-s[i-1]+sum[i-1]*inv[i-1];
			tmp.k=-sum[i-1];
//            cout<<i<<" "<<tmp.k<<" "<<tmp.b<<endl;
			while(q.size()>1&&bad(*(q.end()-2),tmp,*(q.end()-1))) q.pop_back();
			q.PB(tmp);
//			if(q.size()>1){
//			cout<<getval(q.front(),inv[i])<<" "<<getval(q.back(),inv[i])<<" "<<q.size()<<" "<<inv[i]<<endl; 
//			}
			while(q.size()>1&&getval(q.front(),inv[i])>getval(*(q.begin()+1),inv[i])){
			q.pop_front();
			}
			dp[now][i]=getval(q.front(),inv[i])+s[i];
//			cout<<getval(q.front(),inv[i])<<endl;
//			if(q.size()>2){
//				cout<<getval(*(q.begin()+2),inv[i])<<endl;
//			}
//			cout<<i<<" "<<dp[now][i]<<endl;//
//			dp[now][i]=INF;
//			rb(j,id,i-1){
//				dp[now][i]=min(dp[now][i],dp[prev][j]+s[i]-s[j]-sum[j]*inv[i]+sum[j]*inv[j]);
//				cout<<"*"<<j<<" "<<dp[now][i]<<" "<<dp[prev][j]-s[j]-sum[j]*inv[i]+sum[j]*inv[j]<<endl;
//			}
//			cout<<dp[now][i]<<endl;			
		}
		swap(prev,now);
	}
	printf("%.10f\n",dp[prev][n]);
	return 0;
}