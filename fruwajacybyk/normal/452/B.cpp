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

double dist(PII p1,PII p2){
	return sqrt((p1.st-p2.st)*(p1.st-p2.st)+(p1.nd-p2.nd)*(p1.nd-p2.nd));
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==0){
		printf("0 1\n");
		printf("0 %d\n",m);
		printf("0 0\n");
		printf("0 %d\n",m-1);
		return 0;
	}
	if(m==0){
		printf("1 0\n");
		printf("%d 0\n",n);
		printf("0 0\n");
		printf("%d 0\n",n-1);
		return 0;
	}
	vector<PII> v;
	v.pb(mp(0,0));
	v.pb(mp(n,0));
	v.pb(mp(0,m));
	v.pb(mp(n,m));
	vector<PII> w;
	FOR(i,0,n+1) FOR(j,0,m+1){
		FOR(k,0,4){
			if(dist(mp(i,j),v[k]) < 5){
				w.pb(mp(i,j));
				break;
			}
		}
	}
	VI dla;
	double best = 0;
	FOR(i1,0,w.size())
		FOR(i2,0,w.size())
			FOR(i3,0,w.size())
				FOR(i4,0,w.size()){
					if(i1!=i2 && i1!=i3 && i1!=i4 && i2!=i3 && i2!=i4 && i3!=i4){
						
						double pos =  dist(w[i1],w[i2])+dist(w[i2],w[i3])+dist(w[i3],w[i4]);
						if(pos>best){
							best = pos;
							VI x; x.pb(i1); x.pb(i2); x.pb(i3); x.pb(i4);
							dla = x;
						}
					}
				}
		

	FOR(i,0,4){
		printf("%d %d\n",w[dla[i]].st,w[dla[i]].nd);
	}


	return 0;
}