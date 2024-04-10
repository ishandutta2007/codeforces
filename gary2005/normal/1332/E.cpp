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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MOD=998244353; 
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1){
		tmp*=A;
		tmp%=MOD;
	}
	return tmp;
}
LL inv(LL A){
	return quick(A,MOD-2);
}
void _minus(LL& A,LL B){
	A+=MOD;
	A-=B;
	A%=MOD;
}
#define mat vector<vector<LL> >   
mat mul (mat A,mat B){
	mat res;
	res=vector<vector<LL> > 
	((int)A.size(),vector<LL> ((int)B[0].size(),0ll));
	rep(i,res.size()){
		rep(j,res[0].size()){
			rep(k,B.size()){
				res[i][j]+=A[i][k]*B[k][j]%MOD;
//				cout<<A[i][k]<<" "<<B[k][j]<<endl;
				res[i][j]%=MOD;
			}
		}
	}
	return res;
}
mat quick_(mat A,LL times_){
	if(times_==0){
		mat  res;
		res.PB(vector<LL> (0));
		res.PB(vector<LL> (0));
		res[0].PB(1);
		res[0].PB(0);
		res[1].PB(0);
		res[1].PB(1); 
		return res;
	}
	mat tmp=quick_(A,times_>>1);
//	cout<<times_<<" "<<endl;
				
	tmp=mul(tmp,tmp);
	if(times_&1){
		tmp=mul(tmp,A);
	}
	
	return tmp;
}
int main(){
	fastio;
	LL n,m,l,r;
	cin>>n>>m>>l>>r;
	r-=l-1;
	if((n*m)%2==1){
		cout<<quick(r,n*m);
	}
	else{
		LL even,odd;
		even=r/2;
		odd=r-even;
		LL x=odd,y=even;
//		cout<<even<<" "<<odd<<endl;
		LL res=quick(r,n*m);
		LL tmp_=0;
//		cout<<x<<" "<<y<<endl;
		if(r&1){
			vector<vector<LL> >  tmp;
			tmp.PB(vector<LL>(0));
			tmp[0].PB(y);
			tmp[0].PB(x);
			tmp.PB(vector<LL>(0)); 
			tmp[1].PB(x);
			tmp[1].PB(y);
			mat init;
			init.PB(vector<LL>  (1,1));
			init.PB(vector<LL> (1,0));
//			mat Tmp=mul(tmp,n*m);
//			rep(i,2){
//			rep(j,2)
//				cout<<tmp[i][j]<<" ";
//				cout<<endl;
//			}
			mat dp=mul(quick_(tmp,n*m),init);
			tmp_=dp[1][0];
//			 cout<<dp[0][0]<<" "<<dp[1][0]<<endl; 
			cout<<(res-tmp_+MOD)%MOD<<endl; 
		} 
		else
		cout<<(res*inv(2))%MOD<<endl; 
	}
	return 0;
}