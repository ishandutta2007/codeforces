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


using namespace std;

int n;
int a[1000007];

int fen[1000007];
int jest[1000007];
int wogole[1000007];

void add(int u,int ile){
	while(u<=n){
		fen[u]+=ile;
		u = u + (u & -u);
	}
}

int ask(int u){
	int sum = 0;
	while(u>0){
		sum+=fen[u];
		u = u-(u & -u);
	}
	return sum;
}

int main(){
	scanf("%d",&n);
	vector<PII> v;
	FOR(i,0,n){
		int u; scanf("%d",&u);
		v.pb(mp(u,i));
	}
	sort(v.begin(),v.end());
	int akt = 0;
	int wpis = 0;
	FOR(i,0,n){
		if(v[i].st==akt) a[v[i].nd] = wpis;
		else{
			akt=v[i].st;
			wpis++; 
			a[v[i].nd] = wpis;
		}	
	}
	int maxA = wpis;
	lint ans = 0;
	FOR(i,1,maxA+1){
		jest[i] = 0;
		wogole[i] = 0;
	}
	FOR(i,0,n+1) fen[i] =0;
	FOR(i,0,n) wogole[a[i]]++;
	

	FOR(i,0,n){
		int akt = a[i];
		int potrzeba = wogole[akt]-jest[akt];
		ans+= ask(n)-ask(potrzeba);
		
		add(jest[akt]+1,1);
		jest[akt]++;
	}
	cout<<ans<<endl;


}