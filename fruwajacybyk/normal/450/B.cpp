#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define sz(x) ((int)(x).size())

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int
#define int long long 

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define max_n 200005


using namespace std;

int mod = 1e9+7;

vector<VI> razy(const vector<VI>& v, const vector<VI>& w){
	vector<VI> res;
	FOR(i,0,2) res.pb( VI(2));
	FOR(i,0,2) FOR(j,0,2) FOR(k,0,2) 
		res[i][j] = (res[i][j]+ (v[i][k]*1LL*w[k][j])%mod)%mod;
	return res;
}


vector<VI> power(vector<VI>& v, int n){
	if(n==0){
		vector<VI> res;
		FOR(i,0,2) res.pb( VI(2));
		FOR(i,0,2) FOR(j,0,2) res[i][j] = (i==j ? 1 : 0);
		return res;
	}
	vector<VI> x = power(v,n/2);
	if(n%2==0) return razy(x,x);
	else return razy(v,razy(x,x));
}




#undef int
int main(){
#define int long long 
	int x,y; cin>>x>>y; 
	int n; cin>>n;
	x = (x+mod)%mod;
	y = (y+mod)%mod;
	VI res;
	res.pb(x); res.pb(y);
	if(n<3){
		cout<<res[n-1]<<endl;
		return 0;
	}
	vector<VI> fibi;
	FOR(i,0,2) fibi.pb(VI(2));
	FOR(i,0,2) FOR(j,0,2) fibi[i][j] = 1;
	fibi[0][1] = mod-1; fibi[1][1] = 0;

	vector<VI> ans = power(fibi,n-2);
	cout<<((ans[0][0]*y)%mod+(ans[0][1]*x)%mod)%mod<<endl;
}