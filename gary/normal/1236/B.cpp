/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
*/
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MOD=1e9+7;
LL pow_(LL a,LL b){
	if(b==1) return a%MOD;
	if(b==0) return 1;
	if(b&1){
		LL tmp=pow_(a,b/2);
		return ((((a%MOD)*(tmp%MOD))%MOD)*tmp)%MOD;
	}
	else{
			LL tmp=pow_(a,b/2);
		return ((tmp%MOD)*tmp)%MOD;
	}
}
int main(){
	LL a,b;
	cin>>a>>b;
	cout<<pow_(pow_(2,b)-1,a);
	
	return 0;
}