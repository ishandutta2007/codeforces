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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int main(){
	LL b;
	cin>>b;
	LL res=0;
	for(LL i=1;i*i<=b;i++){
		if(b%i==0){
			if(i*i!=b){
				res+=2;
			}
			else{
				res+=1;
			}
		}
	} 
	cout<<res<<endl;
	return 0;
}