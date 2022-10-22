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
typedef pair<LL,int> mp;
typedef pair<mp,mp> superpair;
map<LL,int> cnt;
map<LL,LL> TOT;
LL a[7000+10],b[7000+10];
vector<mp >  v;
vector<LL> num;
int main(){
	int n;
	cin>>n;
	rb(i,1,n) cin>>a[i],cnt[a[i]]++;
	rb(i,1,n) cin>>b[i],TOT[a[i]]+=b[i];
	for(map<LL,int> :: IT ite=cnt.begin();ite!=cnt.end();ite++){
		v.PB({ite->FIR,ite->SEC});
	}
	LL res=0;
	for(auto it:v){
		if(it.SEC>=2){
			res+=TOT[it.FIR];
			num.PB(it.FIR);
		}
	}
	for(auto it : v){
		if(it.SEC<2){
			int flag=1;
			for(auto it2:num){
				if((it2|it.FIR)==it2){
					flag=0;
				}
			}
			if(!flag) res+=TOT[it.FIR]; 
		}
	}
	cout<<res<<endl;
	return 0;
}