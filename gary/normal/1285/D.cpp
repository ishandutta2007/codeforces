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
vector<LL > v;
int n;
LL dfs(int now,vector<LL> v){
	LL res=0;
	if(now==0) return res;
	vector<LL> v1,v2;
	for(auto it:v){
		if(it&(1ll<<(now-1))){
			v1.PB(it);
		}
		else{
			v2.PB(it);
		}
	}
	if(v1.size()==0||v2.size()==0){
		if(v1.size())
		return dfs(now-1,v1);
		else{
			return dfs(now-1,v2);
		}
	}
	else{
		return (1ll<<(now-1))+min(dfs(now-1,v1),dfs(now-1,v2));
	}
} 
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
		{
			 LL ai;
			 cin>>ai;
			 v.PB(ai);
		}
	 
	cout<<dfs(30,v)<<endl;
	return 0;
}