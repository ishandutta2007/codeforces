//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	int n;
	cin>>n;
	LL XorNum=0;
	rep(i,n){
		LL xi,mi;
		cin>>xi>>mi;
		if(xi&(LL)(1)){
			XorNum^=xi;
			xi++;
			mi--;
		}
		if(mi){
			LL las=xi+mi-1;
			if(!(las&(LL)(1))){
				XorNum^=las;
			}	
			mi>>=1;
			if(mi&(LL)(1)){
				XorNum^=1;
			}
		}
	}
	if(XorNum){
		cout<<"tolik"<<endl;
	}
	else{
		cout<<"bolik"<<endl;
	}
	return 0;
}