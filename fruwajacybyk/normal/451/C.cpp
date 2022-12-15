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
	int z; 
	scanf("%d",&z);
	while(z--){
		lint n,k,d1,d2;
	//	cin>>n>>k>>d1>>d2;
		scanf("%I64d%I64d%I64d%I64d",&n,&k,&d1,&d2);
		if(n%3!=0) printf("no\n");
		else{
			bool flaga = false;
			FOR(i,-1,2) FOR(j,-1,2){
				if(i*j!=0){
					if((k-i*d1-j*d2)%3!=0) continue;
					lint y = (k-i*d1-j*d2)/3; 
					if(y<0) continue;
					lint x = y+i*d1;
					lint z = y+j*d2;
					if(x<0 || z<0) continue;
					
					vector<lint> v;
					v.pb(x); v.pb(y); v.pb(z);
					sort(v.begin(),v.end());
					if(2*v[2]-v[0]-v[1]<=(n-k)) flaga = true;
				}
			}
			if(flaga) printf("yes\n");
			else printf("no\n");
		}
	}

	return 0;
}