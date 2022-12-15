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

#define max_n 200005
#define HEAP priority_queue 

using namespace std;

int b;
VI x;
VI y;
int ans;

void res(int u){
	if(u-b<2) { ans+=(u-b); return;}
	int best = u-1;
	y.clear();
	FORE(i,x){
		int v = *i;
		if(u%v==0){
			y.pb(v);
			continue;
		}
		int k = (u/v)*v;
		if( k >= b){
			best = min(best,k);
			y.pb(v);
		}
	}
	x = y;
	ans++;
	res(best);
}


int main(){
	int n;
	scanf("%d",&n);
	int u;
	FOR(i,0,n){
		scanf("%d",&u); x.pb(u);
	}
	sort(x.begin(),x.end());
	VI::iterator it = unique(x.begin(),x.end());
	x.resize(it-x.begin());
	int a;
	scanf("%d%d",&a,&b);
	if(a-b<2){
		printf("%d\n",a-b);
		return 0;
	}
	ans = 0; res(a);
	printf("%d\n",ans);
}