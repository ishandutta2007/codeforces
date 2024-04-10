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
int n,m,a[304][304];
void solve(){
	R2(n,m);
	rb(i,1,n)
		rb(j,1,m)
			R(a[i][j]);
	rb(i,1,n){
		rb(j,1,m){
			if(a[i][j]>4){
				cout<<"NO"<<endl;
				return ;
			}
		}
	}	
	if(a[1][1]>2||a[1][m]>2||a[n][1]>2||a[n][m]>2){
		
				cout<<"NO"<<endl;
				return ;
	}
	rb(i,1,m)
		if(a[1][i]>3||a[n][i]>3){
			
				cout<<"NO"<<endl;
				return ;
		}
	rb(i,1,n)
		if(a[i][1]>3||a[i][m]>3){
			
				cout<<"NO"<<endl;
				return ;
		}
	cout<<"YES"<<endl;
	cout<<2<<" ";
	rb(i,1,m-2) cout<<3<<" ";
	cout<<2<<endl;
	rb(i,1,n-2){
		cout<<3<<" ";
		rb(i,1,m-2)
			cout<<"4 ";
		cout<<3<<endl;
	}
	cout<<2<<" ";
	rb(i,1,m-2) cout<<3<<" ";
	cout<<2<<endl;
}
int main(){
	int t;
	R(t);
	while(t--) solve(); 
	return 0;
}