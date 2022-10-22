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
int main(){
	LL k,a,b;
	cin>>k>>a>>b;
	LL tota=0,totb=0;
	tota=abs(a)/k;
	totb=abs(b)/k;
	if((a<0&&b<0)||(a>0&&b>0)){
		if((a<0&&b<0)){
			cout<<tota-totb+bool(!(abs(b)%k));
		}
		else{
			cout<<totb-tota+bool(!(a%k));	
		}
	}
	else{
		cout<<tota+totb+1<<endl;
	}
	return 0;
}