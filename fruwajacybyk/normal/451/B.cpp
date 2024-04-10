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
	VI v;
	scanf("%d",&n);
	FOR(i,0,n){
		int a;
		scanf("%d",&a);
		v.pb(a);
	}
	int start = -1;
	int meta = n-1;
	FOR(i,0,n-1) 
		if(v[i]>v[i+1]){
			start = i;
			break;
		}
	if(start==-1){
		printf("yes\n1 1\n");
		return 0;
	}
	
	FOR(i,start,n-1) 
		if(v[i]<v[i+1]){
				meta = i;
				break;
		}

	VI w;
	FOR(i,0,start) w.pb(v[i]);
	FORD(i,meta,start) w.pb(v[i]);
	FOR(i,meta+1,n) w.pb(v[i]);


	sort(v.begin(),v.end());
	FOR(i,0,n){
		if(v[i]!=w[i]){
			printf("no\n");
			return 0;
		}
	}
	printf("yes\n%d %d\n",start+1,meta+1);

	


	return 0;
}