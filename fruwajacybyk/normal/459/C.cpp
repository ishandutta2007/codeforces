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

int n,k,d;

bool dasie(){
	if(k>=n) return true;
	if(n==1) return true;
	lint u = 1LL;
	FOR(i,0,d){
		u*=k*1LL;
		if(u>=n) return true;
	}
	return false;
}


int main(){
	scanf("%d%d%d",&n,&k,&d);
	if(!dasie()){
		printf("-1\n");
	}
	else{
		int t[10005]; FOR(i,0,10005) t[i] = i;
		FOR(i,0,d){
			FOR(j,0,n){
				printf("%d ", (t[j]%k)+1);
				t[j]=t[j]/k;
			}
			printf("\n");
		}
	}

}