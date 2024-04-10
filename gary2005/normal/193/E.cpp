/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const LL MOD=1e13;
struct Matrix{
	int n,m;
	LL a[3][3];
	Matrix(){
		memset(a,0,sizeof(a));
	}
	void debug(){
		cout<<n<<" "<<m<<endl;
		rb(i,1,n)
			rb(j,1,m){
				cout<<a[i][j]<<" ";
				if(j==m) cout<<endl;
			}
	}
};
Matrix multiplication(Matrix A,Matrix B){
	Matrix result;
	memset(result.a,0,sizeof(result.a));
	if(A.m!=B.n){
		cout<<"------\n";
		cout<<"|erro|\n";
		cout<<"------\n";
		cout<<"A can't multiply B \n"; 
		exit(0);
	}
	result.n=A.n;
	result.m=B.m;
	rb(i,1,A.n){
		rb(j,1,B.m){
			rb(k,1,A.m){
				__int128 A_,B_;
				A_=A.a[i][k];
				B_=B.a[k][j];
				result.a[i][j]+=A_*B_%MOD;
				result.a[i][j]%=MOD;
			}
		}
	}
	return result;
}
Matrix quick_pow(Matrix A,LL times){
	if(times==0){
		Matrix res;
		res.m=res.n=A.n;
		memset(res.a,0,sizeof(res.a));	
		rb(i,1,res.m){
			res.a[i][i]=1;
		}
		return res;
	}
	Matrix res=quick_pow(A,times>>1);
	res=multiplication(res,res);
	if(times&1) res=multiplication(res,A);
	return res;
}
int main(){
	LL f;
	scanf("%lld",&f);
	LL f0,f1;
	f0=0,f1=1;
	LL p=0;
	vector<LL> s;
	while(true){
		if(p&&f0==0&&f1==1) break;
		if(f0==f%10000000){
			s.PB(p);
		}
		LL f2=(f0+f1)%(10000000);
		f0=f1;
		f1=f2;
		++p;
	}
	Matrix trans;
	trans.n=trans.m=2;
	trans.a[2][1]=1;
	trans.a[1][2]=1;
	trans.a[2][2]=1;
	trans=quick_pow(trans,p);
	LL ans=1e16;
	for(auto it:s){
		Matrix tmptrans;
		tmptrans.n=tmptrans.m=2;
		tmptrans.a[2][1]=1;
		tmptrans.a[1][2]=1;
		tmptrans.a[2][2]=1;
		tmptrans=quick_pow(tmptrans,it);
		LL x=it;
//		tmptrans.debug();
//		cout<<it<<endl; 
//		cout<<tmptrans.a[2][1]<<" "<<it<<endl;
		rb(i,1,2000000){
			if(x>ans) break;
			if(tmptrans.a[2][1]==f){
				check_min(ans,x);
				break;
			}
			x+=p;
			tmptrans=multiplication(tmptrans,trans);
		}
	}
	if(ans<1e15) cout<<ans<<endl;
	else
	puts("-1");
	return 0;
}