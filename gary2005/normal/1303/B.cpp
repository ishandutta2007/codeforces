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
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		LL n,g,b;
		cin>>n>>g>>b;
		
		LL save=n;
		n=(n+1)/2;
		save-=n;
		LL tmp=(n)/(g);
		if(n%g==0){
			save-=(b)*(tmp-1);
			tmp*=(b+g);
			tmp-=b;
			if(save>0)
			tmp+=save;
		} 
		else{
			save-=b*(tmp);
			tmp*=b+g;
			if(save>0)
			tmp+=save;
			tmp+=n%g;
		}
		cout<<tmp<<endl;
	}
	return 0;
}