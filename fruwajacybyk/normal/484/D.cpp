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
#define max_n 1000005

vector<lint> v;
lint dp[max_n];
int inc[max_n];
int decr[max_n];

int n,N;
vector<lint> rt1;
vector<lint> rt2;

void init(vector<lint>& rt,int start){
	for(N=1; N<n+1; N<<=1);
	rt = vector<lint>(N<<1);
	rt[N] = 0;
	FOR(i,1,N) rt[i+N] = (i<=n  ? start*v[i-1] : -1e9);
	FORD(i,N-1,1){
		rt[i] = max(rt[i<<1],rt[(i<<1)|1]);
	}
}

// w przedziale x,y reprezentowanym przez v
// szukaj przedziau l,r 
lint rob(int v, int x, int y, int l, int r,vector<lint>& rt){
	if(l > r) return -1e9;
	if( l == x &&  r == y){
		return rt[v];
	}
	int mid = (x+y)/2;
	lint u1 = rob(2*v,x,mid,l,min(r,mid),rt);
	lint u2 = rob(2*v+1,mid+1,y,max(l,mid+1),r,rt);
	return max(u1,u2);
}

void change(int v, lint x,vector<lint>& rt){
	rt[v+N] = x;
	for(int j = (v+N)>>1; j ; j>>=1){
		rt[j] = max(rt[j<<1],rt[(j<<1)|1]);
	}
}

// rt1 --> dp[i]-v[i-1] typu max
// rt2 --> dp[i]+v[i-1] typu max


int main(){
	read(n);
	FOR(i,0,n){
		make(a); v.pb(a*1LL);
	}
	inc[n-1] = decr[n-1] = n-1;
	FORD(i,n-2,0){
		inc[i] = decr[i] = i;
		if(v[i] > v[i+1]) decr[i] = decr[i+1];
		if(v[i] < v[i+1]) inc[i] = inc[i+1];
	}

	init(rt1,-1);
	init(rt2,1);	

	FORD(i,n-1,0){
		lint x1 = rob(1,0,N-1,i+1,decr[i]+1,rt1)+v[i];
		lint x2 = rob(1,0,N-1,i+1,inc[i]+1,rt2)-v[i];	
		if(i!=0){
			change(i,max(x1,x2)-v[i-1],rt1);
			change(i,max(x1,x2)+v[i-1],rt2);
		}
		else printf("%I64d\n",max(x1,x2));
	}



	return 0;
}