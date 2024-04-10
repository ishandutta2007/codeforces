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
#define all(x) x.begn(),x.end()

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
#define IOS ios_base::sync_with_stdio(0)


#define max_n 2000005


using namespace std;

vector<VI> v[6];
VI now[10];


lint d(int a,int b){
	lint res = 0;
	FOR(i,0,3) res+= (now[a][i]-now[b][i])*1LL*(now[a][i]-now[b][i]);
	return res;
}

bool check(){
	lint side = 0;
	vector<lint> dists[10];
	FOR(i,0,8){
		FOR(j,i+1,8){
			lint u = d(i,j);
			dists[i].pb(u); dists[j].pb(u);
		}
	}
	FOR(i,0,8) sort(dists[i].begin(),dists[i].end());
	side = dists[0][0]; if(side==0) return false;
	FOR(i,0,8) FOR(j,0,3) if(dists[i][j]!=side) return false;
	FOR(i,0,8) FOR(j,3,6) if(dists[i][j]!=2*side) return false;
	FOR(i,0,8) if(dists[i][6]!=3*side) return false;
	return true;
}




int main(){
	IOS;
	FOR(i,0,8){
		VI w; make3(a,b,c);
		w.pb(a); w.pb(b); w.pb(c);
		FOR(j,0,6){
			v[j].pb(w);
			next_permutation(w.begin(),w.end());
		}
	}
	FOR(i,0,6*6*6*6*6*6*6){
		int mask = i;
		now[0] = v[0][0];
		FOR(j,1,8){
			now[j] = v[mask%6][j];
			mask=mask/6;
		}
		if(check()){
			cout<<"YES"<<endl;
			FOR(k,0,8){
				FOR(j,0,3)
					cout<<now[k][j]<<" ";
				cout<<endl;
			}
			return 0;
		}
	}
	cout<<"NO"<<endl;



	


	

		



	return 0;
}