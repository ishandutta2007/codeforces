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

#define max_n 100005


using namespace std;

vector<PII> res;
VI primes;
VI niedojdy;
int pierwsze[max_n];
int wziete[max_n];

int main(){
	int n; scanf("%d",&n);
	FOR(i,0,n+1) pierwsze[i] = 0;

	FOR(i,2,n+1){
		if(pierwsze[i]==0){
			primes.pb(i);
			for(int j = 2*i; j<=n ;j+=i){
				pierwsze[j] = i;
			}
		}
	}
	FOR(i,0,n+1) wziete[i] = 0;
	FORD(i,primes.size()-1,0){
		int akt = -1;
		int p = primes[i];
		
		if(p!=2 && 2*p<=n){
			VI w;
			for(int j = 3*p;j<=n;j+=p)
				if(!wziete[j]) w.pb(j);
			
			if(w.size()%2==0){
				w.pb(p); w.pb(2*p);
				FOR(j,0,w.size()/2){
					res.pb(mp(w[2*j],w[2*j+1]));
					wziete[w[2*j]]=wziete[w[2*j+1]]=1;
				}
			}
			else{
				w.pb(p);
				FOR(j,0,w.size()/2){
					res.pb(mp(w[2*j],w[2*j+1]));
					wziete[w[2*j]]=wziete[w[2*j+1]]=1;
				}
				niedojdy.pb(2*p);
				wziete[2*p]=1;
			}
		}
	}
	FOR(i,2,n+1) if(wziete[i]==0 && i%2==0) niedojdy.pb(i);
	if(niedojdy.size()%2==1) niedojdy.pop_back();

	FOR(i,0,niedojdy.size()/2){
		res.pb(mp(niedojdy[2*i],niedojdy[2*i+1]));
	}
	
	printf("%d\n",res.size());
	FOR(i,0,res.size()){
		printf("%d %d\n",res[i].st,res[i].nd);
	}



	

	return 0;
}