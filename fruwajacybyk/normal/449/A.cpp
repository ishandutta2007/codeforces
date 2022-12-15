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
	lint n,m,k; cin>>n>>m>>k;

	if(k > n-1+m-1){
		cout<<-1<<endl;
		return 0;
	}

	lint best = 1;
	
	lint pos1,pos2;
	if(k<=n-1) pos1 = (n/(k+1)) * m;
	else pos1 = (m)/(k-(n-1)+1);

	if(k<=m-1) pos2 = (m/(k+1)) * n;
	else pos2 =  (n)/(k-(m-1)+1);
	
	best = max(pos1,pos2);
	
	cout<<best<<endl;


	return 0;
}