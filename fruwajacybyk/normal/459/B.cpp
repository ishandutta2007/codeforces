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
	int n; scanf("%d",&n);
	int maxi = 0;
	int ile1 = 0;
	int mini = 1e9+1;
	int ile2 = 0;
	FOR(i,0,n){
		int a;
		scanf("%d",&a);
		if(a==mini) ile2++;
		if(a<mini){
			ile2=1;
			mini = a;
		}
		if(a==maxi) ile1++;
		if(a>maxi){
			ile1=1;
			maxi = a;
		}
	}
	if(maxi==mini){
		cout<<0<<" "<<(ile1*1LL*(ile1-1))/2LL<<endl;
	}
	else 
		cout<<maxi-mini<<" "<<ile1*1LL*ile2<<endl;
}