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


int main(){
	int n; 
	scanf("%d\n",&n);
	set<pair<char, char > > s;
	set<char> pos;
	FOR(i,0,n){
		char C='\n',D; 
		while(C=='\n') C = getchar();
		while(C==' ') C = getchar();
		D = getchar();
		pos.insert(C); pos.insert(D);
		s.insert(mp(C,D));
	}
	
	int best = pos.size()-2;
	vector<char> v; FORE(i,pos) v.pb(*i);

	FOR(mask,0,1<<pos.size()){
		int cnt = 0;
		bool flaga = false;
		FORE(i,s) FORE(j,s){
			if(*i==*j) continue;

			FOR(k,0,v.size()){
				if((1<<k) & mask){
					char C = v[k];
					int ile = 0;
					if(i->st==C) ile++;
					if(i->nd==C) ile++;
					if(j->st==C) ile++;
					if(j->nd==C) ile++;
					if(ile==1){
						flaga = true;
						break;
					}
				}
			}
			if(flaga) cnt++;
			flaga = false;
		}
		if(cnt==s.size()*(s.size()-1)){
			best = min(best, __builtin_popcount(mask));
		}
	}

	printf("%d\n",best);




	
	return 0;
}