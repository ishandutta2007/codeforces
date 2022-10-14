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
const int MOD=998244353;
const int g=3;
int n,b[101];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp; 
}
const int PHI=998244352;
struct Matrix{int mat[101][101];Matrix(){memset(mat,0,sizeof(mat));}Matrix operator * (Matrix oth){Matrix ret;rb(i,1,n) rb(j,1,n) rb(k,1,n) (ret.mat[i][j]+=1ll*mat[i][k]*oth.mat[k][j]%PHI)%=PHI;return ret;}};
Matrix I(){Matrix mat;rb(i,1,n) mat.mat[i][i]=1;return mat;}
Matrix quick(Matrix & A,int B){
	if(B==0) return I();
	Matrix tmp=quick(A,B>>1);
	tmp=tmp*tmp;
	if(B&1) tmp=A*tmp;
	return tmp;
}
const int M=31600;
int bsgs(int x){
	if(x==1) return 0;
	unordered_map<int,int> um;
	int now=x;
	rep(i,M){
		um[now]=i;
		now=1ll*now*g%MOD;
	}
	int step;
	step=now=quick(g,M);
	rb(i,1,M){
		if(um.find(now)!=um.end())
			return i*M-um[now];
		now=1ll*now*step%MOD;
	}
	cout<<"Wa"<<endl;
	exit(0);
	return 0;
}
LL exGcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL r = exGcd(b,a%b,x,y);
    LL t = x; x = y;
    y = t-a/b*y;
    return r;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&b[i]);
	Matrix tran;
	rb(i,1,n-1) tran.mat[i+1][i]=1;
	rb(i,1,n) tran.mat[n-i+1][n]=b[i];
	int x,y;
	scanf("%d%d",&x,&y);
	y=bsgs(y);
	tran=quick(tran,x-n); 
	int is=tran.mat[n][n];
	int phi=MOD-1;
	int gg=__gcd(phi,is);
	if(is==0){
		if(y==0){
			cout<<1<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		return 0; 
	}
	if(y%gg){
		puts("-1");
		return 0;
	}
	y/=gg;
	LL j,k;
	exGcd(is,phi,j,k);
	phi/=gg;
	j=j*y%phi;
	if(j<0) j+=phi;
	cout<<quick(g,j)<<endl;
	return 0;
}