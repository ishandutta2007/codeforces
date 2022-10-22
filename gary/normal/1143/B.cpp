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
LL dfs(LL now){
	if(now<10) return now;
	LL tmp=now;
	LL dig=1;
	LL muli=1;
	while(1){
		if(now<10) break;
		now/=10;
		dig++;
		muli*=10;
	}
	LL res=now*dfs(tmp-muli*now);
	LL two=1;
	rb(i,1,dig-1) {
		two*=9;
	}
	if(now!=1) two*=(now-1);
	res=max(res,two);
	return res;
}
int main(){
	LL n;
	cin>>n;
	cout<<dfs(n)<<endl;
	return 0;
}