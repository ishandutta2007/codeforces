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
int sum[100000+1],suf[100000+2],a[100000+1];
int main(){
	sum[0]=~0;
	fastio;
	int n;
	cin>>n;
	suf[n+1]=~0;
	rb(i,1,n){
		cin>>a[i];
	}
	rb(i,1,n){
		sum[i]=sum[i-1]&(~a[i]);
	}
	rl(i,n,1){
		suf[i]=suf[i+1]&(~a[i]);
	}
	pair<int,int> res;
res=II(-1,0);
	rb(i,1,n){ 
		int tmp=sum[i-1]&suf[i+1]&a[i];
		if(tmp>res.FIR){
			res=II(tmp,i);
		}
	}cout<<a[res.SEC]<<" ";
	rb(i,1,n){
		if(i!=res.SEC){
			cout<<a[i]<<" ";
		}
	}
	return 0;
}