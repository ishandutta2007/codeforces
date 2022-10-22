/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int a[300000+1],ok1[300000+1],ok2[300000+1];
void solve(){
	int n;
	cin>>n;
	rb(i,1,n)
		cin>>a[i],ok1[i]=ok2[i]=0;
	rb(i,1,n)
	
	{
		if(a[i]>=i-1){
			ok1[i]=1;
		}
		else break;
	}
	rl(i,n,1){
		if(a[i]>=n-i){
			ok2[i]=1;
		}
		else break;
	}
	
	rb(i,1,n){
		if(ok1[i]&&ok2[i]) {
			cout<<"Yes\n";
			return ;
		}
	}
	cout<<"No"<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}