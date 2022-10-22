/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,k,a[100000+20];
int divd[100000+20];
LL rest=0;
priority_queue<pair<LL,int> > q;
LL Q(LL x,LL K){
	if(K>x) return 1000000000000000000ll;
	LL sma=x/K;
	LL big=x-sma*K;
	return big*(sma+1)*(sma+1)+sma*sma*(K-big);
}
signed main(){
	cin>>n>>k;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		rest+=Q(a[i],1);
		divd[i]=1;
		q.push(II(Q(a[i],1)-Q(a[i],2),i));
	}
	rb(i,1,k-n){
		rest-=q.top().FIR;
		int id=q.top().SEC;
		q.pop();
		divd[id]++;
		q.push(II(Q(a[id],divd[id])-Q(a[id],divd[id]+1),id));
	}
	cout<<rest<<endl;
	return 0;
}