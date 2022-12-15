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
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 100005

int k;
int winner;
VI sum1;
VI sum2;

int next1(int i,int u){
	int ile = sum1[i-1]+u;
	if(sum1[k]<ile) return k+1;
	int res = lower_bound(sum1.begin(),sum1.end(),ile)-sum1.begin();
	return res;
}

int next2(int i, int u){
	int ile = sum2[i-1]+u;
	if(sum2[k]<ile) return k+1;
	int res = lower_bound(sum2.begin(),sum2.end(),ile)-sum2.begin();
	return res;
}

int main(){
	scanf("%d",&k);
	VI v;
	FOR(i,0,k){
		make(a); v.pb(a);
	}
	int pktzw = 0;
	sum1.pb( 0);
	sum2.pb(0);
	winner = v[k-1];
	FOR(i,1,k+1){
		if(v[i-1]==winner) pktzw++;
		if(v[i-1]==1){
			sum1.pb(sum1[i-1]+1);
			sum2.pb(sum2[i-1]);
		}
		else{
			sum1.pb(sum1[i-1]);
			sum2.pb(sum2[i-1]+1);
		}
	}
	vector<PII> res;
	/*debug(winner);
	debug(pktzw);
	debugv(sum1);
	debugv(sum2);
	*/
	FOR(t,1,pktzw+1){
		int pos = 1;
		int w1 = 0, w2 = 0;
		bool dobra = true;
		while(pos<=k){
			int n1 = next1(pos,t);
			int n2 = next2(pos,t);
			if(n1>k && n2>k){
				dobra = false;
				break;
			}
			if(n1<n2) {w1++; pos = n1+1;}
			if(n1>n2) {w2++; pos = n2+1;}
		}
		if(dobra){
			if(w1>w2 && winner==1) res.pb(mp(w1,t));
			if(w2>w1 && winner==2) res.pb(mp(w2,t));
		}
	}
	sort(res.begin(),res.end());
	printf("%d\n",res.size());
	FOR(i,0,res.size()){
		printf("%d %d\n",res[i].st,res[i].nd);
	}

	return 0;
}