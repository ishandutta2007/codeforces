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

int power(int a,int k,int p){
	if(k==0) return 1;
	int sq = power(a,k/2,p);
	sq = (sq*1LL*sq)%p;
	if(k%2==0) return sq;
	else return (sq*1LL*a)%p;
}


int main(){
	IOS;
	make(n);
	if(n==4){
		printf("YES\n1\n3\n2\n4\n");
		return 0;
	}
	if(n<4){
		printf("YES\n");
		FOR(i,1,n+1)
			printf("%d\n",i);
		return 0;
	}
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			printf("NO\n");
			return 0;
		}
	}
	int p = n;
	VI divisors;
	FOR(i,1,p-1){
		if((p-1)%i==0) divisors.pb(i);
	}

	int g = 1;
	while(1){
		bool flaga = true;
		FOR(i,0,divisors.size()){
			if(power(g,divisors[i],p)==1){
				g++; flaga = false; break;
			}
		}
		if(flaga) break;
	}
	printf("YES\n");
	printf("1\n");
	VI v;
	FOR(i,0,(p-1)/2){
		if(i%2==0){
			v.pb(i+1);
		}
		else{
			v.pb((p-1)-(i+1));
		}
	}
	int x = v.size();
	FOR(i,1,x){
		v.pb(p-1-(v[x-1-i]));
	}	
	FOR(i,0,v.size()){
		printf("%d\n",power(g,v[i],p));
	}
	printf("%d\n",p);

	return 0;
}