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
struct Matrix{
	int n,m;
	int a[202][202];
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
				result.a[i][j]+=1ll*A.a[i][k]*B.a[k][j]%MOD;
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
int id[202],len[202],ano[202],cnt=0;
map<pair<mp,int> ,int> M;
string s[202];
bool equ(int a,int b,int c,int d){
	//a: [c,c+d-1]  = b: [0,d]?
	if(d+c-1>=s[a].length()||d>s[b].length()) return 0;
	rep(i,d){
		if(s[a][c+i]!=s[b][i]) return 0;
	}
	return true;
}
Matrix trans;
int n,m;
void chk(int i,int j,int k){
	int id=M[II(II(i,j),k)];
	if(j==s[i].length()-1){
		vector<int> possi;
		rb(z,1,n){
			if(equ(i,z,j-k,k+1)){
				possi.PB(z);
			}
		}
		for(auto it:possi){
			if(k+1==s[it].length()){
				rb(z,1,n){
					trans.a[id][M[II(II(z,0),0)]]++;
				}
			}
			else{
				trans.a[id][M[II(II(it,k+1),0)]]++;
			}
		}
	}
	else{
		trans.a[id][M[II(II(i,j+1),k+1)]]++;
		rb(z,1,n){
			if(equ(i,z,j-k,k+1)&&k+1==s[z].length()){
				trans.a[id][M[II(II(i,j+1),0)]]++;
			}
		}
	}
}
int ret[202];
int old[202];
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n){
		cin>>s[i];
		rb(j,0,s[i].length()-1){
			rb(k,0,j){
				cnt++;
				id[cnt]=i;
				len[cnt]=j;
				ano[cnt]=k;
				M[II(II(i,j),k)]=cnt;
			}
		}
	}
	trans.n=trans.m=cnt;
	rb(i,1,n) rb(j,0,s[i].length()-1) rb(k,0,j) chk(i,j,k);
	trans=quick_pow(trans,m);
	rb(i,1,n) old[M[II(II(i,0),0)]]=1;
	rb(i,1,cnt){
		rb(j,1,cnt){
			(ret[i]+=1ll*old[j]*trans.a[j][i]%MOD)%=MOD;
		}
	}
	cout<<ret[M[II(II(1,0),0)]]<<endl;
	return 0;
}