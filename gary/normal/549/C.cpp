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
int totJ,totO;
int main(){
	int n,k;
	cin>>n>>k;
	rep(i,n)
	{
		int ai;
		cin>>ai;
		if(ai&1){
			totJ++;
		}
		else{
			totO++;
		}
	}
	k=n-k;
	if(!k){
		if(totJ&1){
			cout<<"Stannis";
		}
		else{
			cout<<"Daenerys";
		}
		return 0;
	}
	if(totO<=(k>>1)+bool(k&1)&&((totJ+totO-k)&1)){
		cout<<"Stannis";
		return 0;
	}
	if(totO<=(k>>1)&&!((totJ+totO-k)&1)){
		cout<<"Daenerys";
		return 0;
	}
	int OK=1;
	if((k&1)==0||totJ<=(k>>1)){
		OK=0;
	}
	if(OK==0) cout<<"Daenerys";
	else cout<<"Stannis";
	return 0;
}