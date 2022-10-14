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
int n,m;
map<int,int> pos;
mp a[303];
int dp[303][303][303];
int is[303];
int l[103],r[103],b[103];
int ma[303];
vector<mp> A[103][103],B[103][103];
int f[303][303];
bool vis[303][303];
int dfs(int l,int r){
	if(l>r) return 0;
	if(vis[l][r]) return f[l][r];
	vis[l][r]=true;
	int & ret=f[l][r];
	ret=0;
	int l_,r_;
	l_=is[l];
	r_=is[r+1]-1;
	if(l_>r_) return ret;
	if(dp[l][l_][r_]>=r){
		ret=ma[r]-ma[l];
	}
	else{
		check_max(ret,dfs(l+1,r));
		check_max(ret,dfs(l,r-1));
		rb(i,l+1,r)
			check_max(ret,dfs(l,i-1)+dfs(i,r));
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d%d",&a[i].FIR,&a[i].SEC);
	sort(a+1,a+1+n);
	rb(i,1,n) pos[a[i].FIR]=pos[a[i].FIR-a[i].SEC]=pos[a[i].FIR+a[i].SEC]=1;
	for(auto ite=pos.begin();ite!=pos.end();++ite){
		ite->SEC=++m;
		ma[m]=ite->FIR;
	}
	rb(i,1,n) b[i]=pos[a[i].FIR],l[i]=pos[a[i].FIR-a[i].SEC],r[i]=pos[a[i].FIR+a[i].SEC];
	rb(i,1,n){
		rb(k,1,b[i]){
			if(k==b[i]) dp[k][i][i]=r[i];
			else{
				if(k<l[i]) dp[k][i][i]=k;
				else dp[k][i][i]=b[i];
			}
		}
	}
	rb(i,1,n) rb(j,1,n) {
		A[i][j].PB({INF,-INF});
		B[i][j].PB({-INF,INF});	
		A[i][j].PB({INF,-INF});
		B[i][j].PB({-INF,INF});	
	}
	rb(i,1,n) rb(k,1,b[i]) dp[k][i][i-1]=k;
	rb(i,1,n) rb(j,i,n){
		rb(k,i,j) A[i][j].PB({l[k],r[k]});
		rb(k,i,j) B[i][j].PB({r[k],l[k]});
		sort(ALL(A[i][j]));	
		sort(ALL(B[i][j]));
		reverse(ALL(B[i][j]));
	}
	rb(i,1,m+1) is[i]=n+1;
	rb(i,1,n) is[b[i]]=i;
	rl(i,m,1) check_min(is[i],is[i+1]);
	rb(i,1,n)
		rb(j,i+1,n){
			rb(k,1,b[i]){
				if(dp[k][i][j-1]>=b[j]){
					dp[k][i][j]=max(dp[k][i][j-1],r[j]);
				}
					int l_,r_;
					r_=j-1;
					l_=max(i,is[l[j]]);
					if(l[j]<=dp[k][i][l_-1]){
						check_max(dp[k][i][j],max(b[j],B[l_][r_][0].FIR));
					}
					else{
						if(A[l_][r_][0].FIR>dp[k][i][l_-1]){
							check_max(dp[k][i][j],dp[k][i][j-1]);
						}
						else{
							if(A[l_][r_][1].FIR<=dp[k][i][l_-1]||A[l_][r_][0].SEC!=B[l_][r_][0].FIR){
								dp[k][i][j]=max(dp[k][i][j],max(b[j],B[l_][r_][0].FIR));
							}
							else{
								dp[k][i][j]=max(max(b[j],B[l_][r_][1].FIR),dp[k][i][j]);
							}
						}
					}
				check_max(dp[k][i][j],dp[k][i][j-1]);
				if(l[j]<=dp[k][i][j-1]) check_max(dp[k][i][j],b[j]);
			}
		}
	cout<<dfs(1,m)<<endl; 
	return 0;
}