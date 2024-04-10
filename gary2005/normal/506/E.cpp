/**
 *    author:  gary
 *    created: 08.06.2022 14:01:47
**/
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
const int MOD=1e4+7;
struct Matrix{
	int n,m;
	int a[220][220];
	Matrix(){
		memset(a,0,sizeof(a));
	}
};
Matrix multiplication(Matrix A,Matrix B){
	Matrix result;
	memset(result.a,0,sizeof(result.a));
	result.n=A.n;
	result.m=B.m;
	rb(i,1,A.n){
		rb(k,i,A.m){
            if(A.a[i][k]){
              int val=A.a[i][k];
      		    for(int j=k;j<=A.n;j+=8){
                      result.a[i][j]+=val*B.a[k][j];
                      result.a[i][j+1]+=val*B.a[k][j+1];
                      result.a[i][j+2]+=val*B.a[k][j+2];
                      result.a[i][j+3]+=val*B.a[k][j+3];
                      result.a[i][j+4]+=val*B.a[k][j+4];
                      result.a[i][j+5]+=val*B.a[k][j+5];
                      result.a[i][j+6]+=val*B.a[k][j+6];
                      result.a[i][j+7]+=val*B.a[k][j+7];
      			}
            }
            if(!(k&15)||k==A.m){
                rb(j,i,A.n)
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
int dp[202][202][202];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n;
    cin>>n;
    dp[0][s.length()+1][0]=1;
    int Len=s.length()+n;
    rb(l,0,s.length()) rl(r,s.length()+1,1) rb(j,0,s.length()) if(dp[l][r][j]){
        if(l!=r-1){
            char A,B;
            A=s[l];
            B=s[r-2];
            if(A==B&&l+1<r-1) (dp[l+1][r-1][j+1]+=dp[l][r][j])%=MOD;
            else { (dp[l+1][r][j+1]+=dp[l][r][j])%=MOD;if(l+1!=r-1)(dp[l][r-1][j+1]+=dp[l][r][j])%=MOD;}
        }
    }
    int ans=0;
    map<mp,int> mem;
    if(Len&1){
    rb(i,1,s.length()-1) if(s[i-1]==s[i]) rb(j,0,s.length()) if(dp[i-1][i+2][j])
    {
        int N=s.length()-2;
        (mem[II(2*j-N,N-j+1)]+=26*dp[i-1][i+2][j])%=MOD;
    }
    rb(i,1,s.length()) rb(j,0,s.length()) if(dp[i-1][i+1][j]){
        int N=s.length()-1;
        (mem[II(2*j-N,N-j+1)]+=26*dp[i-1][i+1][j])%=MOD;
    }
    rb(i,1,s.length()) rb(j,0,s.length()) if(dp[i-1][i+1][j]){
        int N=s.length()-1;
        (mem[II(2*j-N,N-j+1+INF)]+=dp[i-1][i+1][j])%=MOD;
    }
    }
    else{
    rb(i,1,s.length()-1) if(s[i-1]==s[i]) rb(j,0,s.length()) if(dp[i-1][i+2][j])
    {
        int N=s.length()-2;
        (mem[II(2*j-N,N-j+1)]+=dp[i-1][i+2][j])%=MOD;
    }
    rb(i,1,s.length()) rb(j,0,s.length()) if(dp[i-1][i+1][j]){
        int N=s.length()-1;
        (mem[II(2*j-N,N-j+1)]+=dp[i-1][i+1][j])%=MOD;
    }
    }
    vector<mp> tmp;
    for(auto it:mem) if(it.second==0) tmp.PB(it.first);
    for(auto it:tmp) mem.erase(it);
    map<int,vector<mp> > tmp2;
    for(auto it:mem) tmp2[it.first.second].PB(II(it.first.first,it.second));
    for(auto it:mem){
        int b=it.first.second;
        int c=it.first.first;
        if(b>=INF) b-=INF;
        Matrix trans;
        trans.n=trans.m=b+c+1;
        rb(i,1,b) trans.a[i][i+1]=1,trans.a[i][i]=25;
        rb(i,b+1,b+c) trans.a[i][i+1]=1,trans.a[i][i]=24;
        trans.a[b+c+1][b+c+1]=26;
        if(it.first.second>=INF) trans.a[b+c+1][b+c+1]=0;
        trans=quick_pow(trans,Len/2+(it.first.second>=INF));
        ans+=it.second*trans.a[1][b+c+1],ans%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}