/*
{

AuThOr Gwj
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}	
*/
int n;
LL rest[1000000+2];
int main(){
	fastio;
	int n;
	R(n);
	LL sum=0;
	rb(i,1,n){
		LL hi;
		R(hi);
		sum+=hi;
	}
	if(n==1){
		cout<<sum<<endl;
		return 0;
	}
	rb(i,1,n){
		rest[i]=i;
		sum-=i;
	}
	rb(i,1,n)
		rest[i]+=sum/n;
	rb(i,1,sum%n)
		rest[i]++;
	rb(i,1,n)
		cout<<rest[i]<<" ";
	return 0;
}