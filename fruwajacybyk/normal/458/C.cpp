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

#define max_n 100005
#define HEAP priority_queue


using namespace std;

int mam;
VI dupa;

bool czy(int x, VI& chlopy){
	int sum = 0;
	FOR(i,0,chlopy.size()){
		sum+= max(chlopy[i]+1-(mam+x),0);
		if(sum > x) return false;
	}
	return true;
}

int ming(){
	int l = 0; int p = 1e5;
	while(p-l>1){
		int sr = (l+p)/2;
		if(czy(sr,dupa)){
			p = sr;
		}
		else l = sr;
	
	}
	if(czy(l,dupa)) return l;
	else return p;
}



int main(){
	int n;
	VI goscie[max_n];
	scanf("%d",&n);
	lint res = 0;

	FOR(i,0,n){
		int a,b;
		scanf("%d%d",&a,&b);
		goscie[a].pb(b);
	}
	
	mam = goscie[0].size();

	vector<VI> przeciwnicy;

	HEAP<int> owce;

	FOR(i,1,1e5+1){
		int kto = goscie[i].size();
		if(kto>0 && kto > mam){
			przeciwnicy.pb(goscie[i]);
			dupa.pb(kto);
		}
		else
			FOR(j,0,goscie[i].size()) owce.push(-goscie[i][j]);
	}

	int best = 1e9;

	int mg = ming();
	if(mg==0){
		printf("0\n");
		return 0;
	}
	int akt = 0;
	int ileOdGosci = 0;
	int odgosci = 0;
	int zreszty = 0;
	multiset<VI> secik;

	FOR(i,0,przeciwnicy.size()){
		if(mam+mg > przeciwnicy[i].size()){
			FOR(j,0,przeciwnicy[i].size()) owce.push(-przeciwnicy[i][j]);
		}
		else{
			int musze = przeciwnicy[i].size()+1-mam-mg;
			ileOdGosci += przeciwnicy[i].size()+1-mam-mg;

			sort(przeciwnicy[i].begin(),przeciwnicy[i].end());
			
			FOR(j,0,musze) odgosci+=przeciwnicy[i][j];
			FOR(j,musze,przeciwnicy[i].size()) owce.push(-przeciwnicy[i][j]);
			
			secik.insert(przeciwnicy[i]);
		}
	}


	FOR(i,0,mg-ileOdGosci){
		zreszty+= -owce.top();
		owce.pop();
	}

	akt = odgosci+zreszty;	

	best = akt;
	FOR(x,mg+1,n+1){
		int jeszcze = 1;
		vector<multiset<VI>::iterator > usuwam;
		FORE(i,secik){
			int musze = i->size()+1-x-mam;
			ileOdGosci--;
			jeszcze++;
			odgosci-= (*i)[musze];
			owce.push( -(*i)[musze]);

			if(musze==0){
				usuwam.pb(i);
			}
		}
		FOR(i,0,usuwam.size()) secik.erase(usuwam[i]);

		if(jeszcze<=owce.size()){
			FOR(i,0,jeszcze){
				zreszty+= -owce.top();
				owce.pop();
			}
			akt = odgosci+zreszty;
			best = min(best, akt);
		}
	}

	printf("%d\n",best);






	


	return 0;
}