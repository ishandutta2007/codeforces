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
LL fact[250000+10];
int n,m;
int main(){
	fastio;
	cin>>n>>m;
	fact[0]=1;
	rb(i,1,n)
		fact[i]=fact[i-1]*i,fact[i]%=m;
	LL res=0;
	rb(i,0,n-1){
		res+=((((LL)(i+1)*fact[i])%m*fact[n-i])%m*(i+1))%m;
		res%=m;
//		cout<<res<<endl;
	}
	cout<<res;
	return 0;
}