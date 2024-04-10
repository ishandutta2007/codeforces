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

int main(){
	int n;
	scanf("%d",&n);
	int x = 0, y = 0;
	VI odd;
	FOR(i,0,n){
		int u;
		scanf("%d",&u);
		if(u%2==0){
			FOR(j,0,u){
				int a;
				scanf("%d",&a);
				if(j<u/2) x+=a;
				else y+=a;
			}
		}
		else{
			FOR(j,0,u){
				int a; scanf("%d",&a);
				if(j<u/2) x+=a;
				else if(2*j+1==u) odd.pb(a);
				else y+=a;
			}
		}
	}
	sort(odd.begin(),odd.end(),greater<int>());
	FOR(i,0,odd.size()){
		if(i%2) y+=odd[i];
		else x+=odd[i];
	}
	cout<<x<<" "<<y<<endl;
}