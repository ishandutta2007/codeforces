//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int MOD=1e9+7;
vector<LL> prim;
bool check(LL x){
	if(x==1) return 0;
	for(LL i=2;i*i<=x;i++){
		if(x%i==0) return 0;
	}
	return 1;
}
LL pow(LL bas,LL mi){
	if(mi==0) return 1;
	if(mi&1){
		LL save=pow(bas,mi/2);
		return (bas*((save*save)%MOD))%MOD;
	}
	else{
		LL save=pow(bas,mi/2);
		return (save*save)%MOD;
	}
}
int main(){	
	LL n,x;
	cin>>x>>n;
	for(LL i=1;i*i<=x;i++){
		if(x%i==0){
			if(check(i)) prim.PB(i); 
			if(x/i!=i){
				if(check(x/i)) 
				prim.PB(x/i);
			}
		}
	}
	LL res=1;
	for(auto it : prim){
		LL zhi=it;
		LL Is=1,mi=0;
		while(1){
			LL has=n/Is;
			if(n/Is>=it)
			has-=(n/(Is*it));
//			cout<<has<<" "<<Is<<endl;
			res*=pow(Is%MOD,has);
			res%=MOD;
//			cout<<res<<endl;
			mi++;
			if(n/Is<it) break;
			Is*=it;
			if(Is>n||Is<=0) break;
		}
	}
	cout<<res<<endl;
	return 0;
}