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
LL b[200000+10],sve[200000+10];
vector<int> each[68];
int main(){
	int n;
	cin>>n;
	rb(i,1,n) scanf("%I64d",&b[i]),sve[i]=b[i];
	rb(i,1,n){
		int tot=0;
		while(!(b[i]&1)){
			b[i]>>=1;
			tot++;
		}
		each[tot].PB(i);
	}
	int res=-INF,is=0;
	rep(i,68){
//		cout<<each[i].size()<<" "<<res<<endl; 
		if(int(each[i].size())>res){
			res=each[i].size();
			is=i;
		}
	}
	cout<<n-res<<endl;
	map<int,int> OK;
	for(auto it :each[is]){
		OK[it]=1;
	}
	rb(i,1,n) if(!OK[i]) cout<<sve[i]<<" ";cout<<endl;
	return 0;
}