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

#define max_n 300005


using namespace std;

int n,m;
int best[max_n];
vector<PII> e;
VI start;
int dp[max_n];


int main(){
	scanf("%d%d",&n,&m);
	FOR(i,0,m){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		e.pb(mp(v,w));
		start.pb(u);
	}
	FOR(i,0,m) dp[i] = -1;
	vector<PII> kolejnosc;
	FOR(i,0,m) kolejnosc.pb(mp(e[i].nd,i));
	FOR(i,0,n+5) best[i] = 0;
	sort(kolejnosc.begin(),kolejnosc.end());
	int last = 1e6;
	VI dokomitu;
	FOR(i,0,m){
		int kto = kolejnosc[m-1-i].nd;
		if(last!=e[kto].nd){
			FORE(j,dokomitu){
				best[start[*j]] = max(best[start[*j]],dp[*j]+1);
			}
			dokomitu.clear();
		}
		
		if(dp[kto]==-1) dp[kto] = best[e[kto].st];
		dokomitu.pb(kto);
		last = e[kto].nd;
	}
	int ans = 0;
	FOR(i,0,m) ans = max(ans,1+dp[i]);
	cout<<ans<<endl;
}