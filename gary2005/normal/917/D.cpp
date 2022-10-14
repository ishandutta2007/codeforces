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
const int MOD=1e9+7;
int quick(int a,int b){
	if(b==0) return 1;
	int tmp=quick(a,b>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(b&1) tmp=1ll*tmp*a%MOD;
	return tmp;
}
int inv(int a){//a 
	return quick(a,MOD-2);
}
struct Matrix{
	vector<vector<int> > mat;
	Matrix (){
	}
	Matrix(vector<vector<int> > m){
		mat=m;
	}
	Matrix(int n){
		//n
		mat.resize(n);
		rep(i,n) mat[i].resize(n); 
	}
	int gauss(){//matdet 
		int n=mat.size();//n 
		int det=1;
		rb(i,1,n){
			int have=i;
			rb(j,i,n) if(mat[j-1][i-1]){
				have=j;
				break;
			}
			if(have!=i){
				if(det)
					det=MOD-det; 
			}
			swap(mat[have-1],mat[i-1]);
			int is=inv(mat[i-1][i-1]);
			rb(j,i,mat[0].size()) mat[i-1][j-1]=1ll*is*mat[i-1][j-1]%MOD;
			det=1ll*det*inv(is)%MOD;
			rb(j,1,n){
				if(j==i) continue;
				int t=mat[j-1][i-1];
				rb(k,i,mat[0].size()){
					mat[j-1][k-1]+=MOD-1ll*t*mat[i-1][k-1]%MOD;
					mat[j-1][k-1]%=MOD;
				}
			}
		}
		return det;
	}
	Matrix operator - (Matrix oth){//n 
		Matrix tmp;
		tmp.mat=mat;
		int n=mat.size();
		rep(i,n) rep(j,n) (tmp.mat[i][j]+=MOD-oth.mat[i][j])%=MOD;
		return tmp;
	}
	Matrix operator + (Matrix oth){//n 
		Matrix tmp;
		tmp.mat=mat;
		int n=mat.size();
		rep(i,n) rep(j,n) (tmp.mat[i][j]+=oth.mat[i][j])%=MOD;
		return tmp;
	}
	void clear(){
		int n=mat.size();
		int m=mat[0].size();
		rep(i,n) rep(j,m)  mat[i][j]=0;
	} 
	void debug(){
		//
		int n=mat.size();
		int m=mat[0].size();
		rep(i,n){
			rep(j,m) printf("%d ",mat[i][j]); 
			printf("\n");
		} 
		printf("------------------\n");
	}
};
int n;
int main(){
	scanf("%d",&n);
	Matrix e(n),d(n),l(n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		u--;
		v--;
		e.mat[u][v]++;
		e.mat[v][u]++;
	}
	Matrix ret(n);
	rep(i,n) ret.mat[i].resize(n+1);
	rb(i,1,n){
		Matrix l0(n-1);
		Matrix w(n);
		rep(j,n) rep(k,n) if(j!=k) w.mat[j][k]=(e.mat[j][k]? i:1);
		d.clear();
		rep(j,n) rep(k,n){
			(d.mat[j][j]+=w.mat[j][k])%=MOD;
		}
		l=d-w;
		rep(j,n-1) rep(k,n-1) l0.mat[j][k]=l.mat[j][k];
//		l0.debug();
		int det=l0.gauss();
//		l.debug();
//		cout<<det<<endl;
		int tmp=1;
		rep(j,n){
			ret.mat[i-1][j]=tmp;
			tmp=1ll*tmp*i%MOD;
		}
		ret.mat[i-1][n]=det;
	}
//	ret.debug();
	ret.gauss();
//	ret.debug();
	rep(i,n){
		printf("%d ",ret.mat[i][n]);
	}
	return 0;
}