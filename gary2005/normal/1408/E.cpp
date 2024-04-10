/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,m;
vector<mp> g[200000+20];
int a[200000+20],b[200000+20];
int fa[200000+20];
int root(int x){
	return fa[x]=(fa[x]==x? x:root(fa[x]));
}
int main(){
	fastio;
	cin>>m>>n;
	LL sum=0;
	rb(i,1,n+m) fa[i]=i;
	rb(i,1,m){
		R(b[i]);
	}
	rb(i,1,n) R(a[i]);
	vector<pair<int,mp > > v;
	rb(i,1,m){
		int A;
		R(A);
		rb(j,1,A){
			int x;
			R(x);
			sum+=a[x]+b[i];
//			cout<<x<<" "<<i+n<<endl;
			v.PB(II(-a[x]-b[i],II(x,i+n)));
		}
	}
	LL rest=0;
	sort(ALL(v));
	for(auto it:v){
		if(root(it.SEC.FIR)!=root(it.SEC.SEC)){
			fa[root(it.SEC.FIR)]=root(it.SEC.SEC);
//			cout<<it.SEC.FIR<<" "<<it.SEC.SEC<<endl;
			rest+=it.FIR;
		}
	}
//	cout<<rest<<endl;
	rest=sum+rest;
	cout<<rest<<endl;
	return 0;
}