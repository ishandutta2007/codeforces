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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
void solve(){
	double d;
	cin>>d;
	if(d*d-4*d<0){
		printf("N\n");
		return;
	}
	double b=(d+sqrt(d*d-4*d))/2.0;
	double a;
	a=(b!=0)? d/b : 0; 
	printf("Y %.9f %.9f\n",a,b);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}