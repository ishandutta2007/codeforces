/*
{By GWj
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
int a[100000+1];
int main(){
	int n;
	R(n);
	rb(i,1,n)
		R(a[i]);
	if(n==1){
		cout<<"1 1"<<endl;
		cout<<1<<endl;
		cout<<"1 1"<<endl;
		cout<<1<<endl;
		a[1]++;
		cout<<"1 1\n";
		a[1]++;
		cout<<-(a[1])<<endl;
		return 0;
	}
	cout<<1<<" "<<n<<endl;
	rb(i,1,n-1){
		int need=0-a[i];
		cout<<1ll*need*n<<" ";
	}
	if(a[n]+n!=0){
		cout<<n<<endl;
		a[n]+=n;
	}
	else{
		cout<<2*n<<endl;
		a[n]+=2*n;
	}
	cout<<1<<" "<<n-1<<endl;
	rb(i,1,n-1){
		int need=0-a[i];
		cout<<-1ll*need*(n-1)<<" "; 
	}
	cout<<endl;
	cout<<n<<" "<<n<<endl;
	cout<<-(a[n])<<endl;
	return 0;
}