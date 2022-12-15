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


using namespace std;

lint dp1[100005];
lint dp2[100005];
int ile[100005];

int main(){
	int n; scanf("%d",&n);
	
	FOR(i,0,100005) ile[i] = dp1[i] = dp2[i] =  0;
	FOR(i,0,n){
		int a;
		scanf("%d",&a); ile[a]++;
	}
	
	dp1[0] = dp2[0] = 0;

	FOR(i,1,100005){
		dp1[i] = ile[i]*1LL*i + (i-2 >= 0 ? max(dp2[i-2],dp1[i-2]) : 0);
		dp2[i] = max(dp1[i-1],dp2[i-1]);
	}

	printf("%I64d\n",max(dp1[100001],dp2[100001]));



	return 0;
}