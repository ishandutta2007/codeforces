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
int m,k;
int mat[1001][1001],a[100000+233];
bool solve(int N){
	rb(i,1,N+2)
		rb(j,1,N+2) mat[i][j]=0;
	deque<mp> v;
	rb(i,1,k) v.PB(II(a[i],i));
	sort(ALL(v));
	reverse(ALL(v));
	int A=0,B=0;
	for(int i=1;i<=N;i+=2){
		for(int j=1;j<=N;j++){
			if(!v.empty()){
				if(A==0) A=v.front().SEC;
				B=v.front().SEC;
				mat[i][j]=v.front().SEC;
				v.front().FIR--;
				while(!v.empty()&&v.front().FIR==0) v.pop_front();
			}
		}
	}
	if(!A||!B);
	else{
		if(A!=B){
			vector<mp> V1,V2;
			for(int i=1;i<=N;i+=2){
				for(int j=1;j<=N;j++){
					if(mat[i][j]==A&&j&1) V1.PB(II(i,j));
					if(mat[i][j]==B&&!(j&1)) V2.PB(II(i,j)); 
				}
			}
			assert(V1.size()>=V2.size());
			rep(i,V2.size()) swap(mat[V1[i].FIR][V1[i].SEC],mat[V2[i].FIR][V2[i].SEC]);
		}
	}
	for(int i=2;i<=N;i+=2){
		for(int j=1;j<=N;j+=2){
			if(!v.empty()){
				mat[i][j]=v.front().SEC;
				v.front().FIR--;
				while(!v.empty()&&v.front().FIR==0) v.pop_front();
			}
		}
	}
	rb(i,1,N)
		rb(j,1,N)
			if(mat[i][j]){
				if(mat[i+1][j+1]==mat[i][j]) return 0;
				if(mat[i+1][j-1]==mat[i][j]) return 0;
				if(mat[i-1][j-1]==mat[i][j]) return 0;
				if(mat[i-1][j+1]==mat[i][j]) return 0;
			}
	if(v.size()) return 0;
	return 1;
}
void solve(){
	scanf("%d%d",&m,&k);
	rb(i,1,k) scanf("%d",&a[i]);
	int l=1,r=ceil(sqrt(2.0*m)+20);
	while(l<r){
		int mid=(l+r)>>1;
		if(solve(mid)) r=mid;
		else l=mid+1;
	}
	solve(l);
	printf("%d\n",l);
	rb(i,1,l){
		rb(j,1,l){
			printf("%d ",mat[i][j]);
		}
		puts("");
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}