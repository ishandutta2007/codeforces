/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
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
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
set<int> s;
int main(){
	fastio;
	int n;
	cin>>n;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			s.insert(i),s.insert(n/i);
		}
	}
	set<LL> res;
	for(auto it:s){
		LL tmp=0;
		int k=it;
		LL cnt=n/k;
		
		tmp=(cnt*(2+(cnt-1)*k))/2;
//		cout<<tmp<<" "<<k<<" "<<cnt<<endl;
		res.insert(tmp);
	}
	for(auto it:res){
		cout<<it<<" ";
	}
	return 0;
}