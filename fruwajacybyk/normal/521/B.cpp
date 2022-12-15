#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;
#define max_n 100005

int mod = 1e9+9;
int deg[max_n]; // na ilu sie opiera
vector<PII> w;
map<PII,int> kl;
VI res;

bool moge(int ja){
	int x = w[ja].st, y = w[ja].nd;
	bool ok = true;
	FOR(i,-1,2){
		if(kl.find(mp(x+i,y+1))!=kl.end()){
			if(deg[kl[mp(x+i,y+1)]]==1) ok = false;
		}
	}
	return ok;
}

int main(){
	make(m);
	FOR(i,0,m) deg[i] = 0;
	FOR(i,0,m){
		make2(x,y);
		kl[mp(x,y)] = i;
		w.pb(mp(x,y));
	}
	FORE(i,kl){
		int x,y;
		x = i->st.st; y = i->st.nd;
		if(kl.find(mp(x-1,y-1))!=kl.end()) deg[i->nd]++;
		if(kl.find(mp(x,y-1))!=kl.end())   deg[i->nd]++;
		if(kl.find(mp(x+1,y-1))!=kl.end()) deg[i->nd]++;
	}
	set<int> duze,male;
	FOR(i,0,m){
		if(moge(i)){
			male.insert(i);
			duze.insert(-i);
		}
	}
	FOR(i,0,m){
		int p ;
		if(i%2==0) p = -(*duze.begin());
		else p = *male.begin();
		res.pb(p);
		duze.erase(-p);
		male.erase(p);
		kl.erase(kl.find(w[p]));
		FOR(j,-1,2){
			PII para = mp(w[p].st+j,w[p].nd+1);
			if(kl.find(para)!=kl.end()){
				deg[kl[para]]--;
			}
		}
		FOR(j,-1,2){
			PII para = mp(w[p].st+j,w[p].nd-1);
			if(kl.find(para)!=kl.end()){
				if(moge(kl[para])){
					duze.insert(-kl[para]);
					male.insert(kl[para]);
				}
			}
		}
		FOR(j,-2,3){
			PII para = mp(w[p].st+j,w[p].nd);
			if(kl.find(para)!=kl.end()){
				if(!moge(kl[para])){
					duze.erase(-kl[para]);
					male.erase(kl[para]);
				}
			}
		}
	}
	int ans = 0;
	FOR(i,0,res.size()){
		ans = (ans*1LL*m)%mod;
		ans %= mod;
		ans = (ans+(res[i]))%mod;
	}
	printf("%d\n",ans);
}