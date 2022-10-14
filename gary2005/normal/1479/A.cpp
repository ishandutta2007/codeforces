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
int q(int i){
	cout<<"? "<<i<<endl;ff;
	int t;
	cin>>t;
	return t;
}
void ans(int k){
	cout<<"! "<<k<<endl;
	return ;
}
void solve(int l,int r){
//	cout<<l<<" "<<r<<endl;
	if(l==r){
		ans(l);
		return ;
	}
	if(l==r-1){
		int L,R;
		L=q(l);
		R=q(r);
		if(L<R) ans(l);
		else ans(r);		 
		return ;
	}
	int mid=(l+r)>>1;
	int A=q(mid);
	int B=q(mid-1);
	int C=q(mid+1);
	if(min(B,C)>A){
		ans(mid);
		return;
	}
	if(B<A){
		solve(l,mid-1);
	}
	else{
		solve(mid+1,r);
	}
}
int main(){
	cin>>n;
	solve(1,n);
	return 0;
}