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
int n,m,k,a[5000];
void sovle(){
	cin>>n>>m>>k;
	rb(i,1,n)
		cin>>a[i]; 
	if(k>=m-1){
		int res=-1;
		rb(i,1,m){
			res=max(res,a[i]);
		}
		rb(i,1,m){
			res=max(res,a[n-i+1]);
		}
		cout<<res<<endl;
		return;
	}
	int res=-1;
	m-=1;
	m-=k;
	rb(i,0,k){
		int tmp=INF;
		int l=i+1,r=n-(k-i);
		rb(j,0,m){
			tmp=min(tmp,max(a[l+j],a[r-(m-j)]));
		}
		res=max(res,tmp);
//		cout<<i<<" "<<tmp<<endl;
	}
	cout<<res<<endl;
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--) sovle();
	return 0;
}