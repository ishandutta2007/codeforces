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
int n;
int a[400000];
void solve(){
	R(n);
	int k;
	R(k);
	rb(i,1,n)
	{
		char c;
		R(c);
		a[i]=c^48;
		if(c=='?'){
			a[i]=2;
		}
	}
	rl(i,n,1){
		if(a[i]!=2){
			if(i>k){
				if(a[i-k]==2||a[i-k]==a[i]){
					a[i-k]=a[i];
				}
				else{
					cout<<"NO"<<endl;
					return ;
				}
			}
		}
	}
	int cnt[2]={0};
	rb(i,1,k){
		if(a[i]!=2){
			cnt[a[i]]++;
		}
	}	
	if(cnt[0]*2>k||cnt[1]*2>k){
		
					cout<<"NO"<<endl;
					return ;
	}
	cout<<"YES"<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}