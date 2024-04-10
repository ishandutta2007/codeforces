/**
 *    author:  gary
 *    created: 24.04.2022 21:53:12
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MOD=998244353;
struct Matrix{
	int n,m;
	LL a[303][303];
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
				result.a[i][j]+=A.a[i][k]*B.a[k][j]%MOD;
                if(result.a[i][j]>=MOD) result.a[i][j]-=MOD;
			}
		}
	}
	return result;
}
Matrix quick_pow(Matrix &A,LL times){
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

const int MAXN=1e2+10;
int n,m,k;
vector<int> g[MAXN];
// int dp[MAXN][MAXN*MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    rb(i,1,m){
        int u,v;
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    // int ans=0;
    // rb(i,1,n){
    //     memset(dp,0,sizeof(dp));
    //     dp[i][0]=1;
    //     rb(j,0,n*n){
    //         rb(u,1,n){
    //             for(auto v:g[u]){
    //                 int s=0;
    //                 rl(k,j,0){
    //                     if((j+1)%2==k%2) (s+=MOD-dp[u][k])%=MOD;
    //                     else (s+=dp[v][k])%=MOD;
    //                 }
    //                 (dp[u][j+1]+=s)%=MOD;
    //             }
    //         }
    //     }
    //     ans+=dp[i][k];
    //     ans%=MOD;
    // }
    // cout<<ans<<endl;
    Matrix trans;
    trans.n=trans.m=n*3;
    rb(i,1,n){
        trans.a[i][i+n]=1;
        trans.a[i+2*n][i+n]=1;
        trans.a[i+n][i+2*n]=1;
        for(auto j:g[i]){
            trans.a[i][j]=1;
            trans.a[i+2*n][j]=1;
        }
        trans.a[i+n][i]=(MOD-g[i].size())%MOD;
    }
    trans=quick_pow(trans,k);
    int ans=0;
    // trans.debug();
    rb(i,1,n) (ans+=trans.a[i][i])%=MOD;
    cout<<ans<<endl;
    return 0;
}