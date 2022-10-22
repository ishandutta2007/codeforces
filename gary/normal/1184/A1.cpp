//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(LL a=b;a<=c;++a)
#define rl(a,b,c) for(LL a=b;a>=c;--a)
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
	LL r;
	cin>>r;
	r--;
	if(r==0) {
		cout<<"NO";
		return 0;
	}
	for(LL i=1;i*i<=r;i++){
		if(r%i==0){
			LL x=i;
			r/=x;
			r-=x;
			r--;
			if(r){
				if((r&1)==0){
					cout<<x<<" "<<r/2;
					return 0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
	return 0;
}