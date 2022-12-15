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

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;

#define max_n 200005


using namespace std;

int sum(lint x){
	int res = 0;
	while(x!=0){
		res+=x%10;
		x = x/10;
	}
	return res;
}


lint f(int a,int b,int c,int x){
	lint u = 1;
	FOR(i,0,a) u*=x*1LL;
	u*=b*1LL;
	u+=c*1LL;
	return u;
}

int main(){
	ios_base::sync_with_stdio(0);
	make3(int,a,b,c);

	VI res;
	FOR(i,1,82){
		lint u = f(a,b,c,i);
		if( u>0 && u<1e9){
			if(sum(u)==i) res.pb(u);
		}
	}
	cout<<res.size()<<endl;
	FOR(i,0,res.size()) cout<<res[i]<<" ";
	cout<<endl;

	return 0;
}