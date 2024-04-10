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
int n;
int x[5005],y[5005];
mp pt[5005];
int p[5005];
bool deg(mp A,mp B,mp C){
	A.FIR-=B.FIR;
	A.SEC-=B.SEC;
	C.FIR-=B.FIR;
	C.SEC-=B.SEC;
	return 1ll*A.FIR*C.FIR+1ll*A.SEC*C.SEC>0;
}
void solve(int l,int r){
	if(r<=2) return ;
	solve(l,r-1);
	while(!deg(pt[p[r-2]],pt[p[r-1]],pt[p[r]])){
		swap(p[r],p[r-1]);
		solve(l,r-1);
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d%d",&x[i],&y[i]),pt[i]=II(x[i],y[i]);	
	rb(i,1,n) p[i]=i;
	srand(time(0));
	random_shuffle(p+1,p+1+n);
	solve(1,n);
	rb(i,1,n){
		cout<<p[i]<<' '; 
	}
	cout<<endl;
	return 0;
}