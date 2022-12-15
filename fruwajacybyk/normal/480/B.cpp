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


#define max_n 10005


using namespace std;

VI v;

void find(int d,vector<PII>& res){
	res.clear();
	int n = v.size();
	int i = 0, j = 0;
	while(j<n){
		if(v[j]-v[i]<d) j++;
		else if(v[j]-v[i]>d) i++;
		else if(v[j]-v[i]==d){
			res.pb(mp(i,j));
			i++;
			j++;
		}
	}
}


int main(){
	IOS;
	make4(n,l,x,y);
	FOR(i,0,n){
		make(a); v.pb(a);
	}
	vector<PII> resX,resY,resSum,resDiff;
	find(x,resX);
	find(y,resY);
	find(x+y,resSum);
	find(y-x,resDiff);
	if(resX.size()!=0 && resY.size()!=0){
		printf("0\n");
	}
	else if(resX.size()!=0){
		printf("1\n");
		printf("%d\n",y);
	}
	else if(resY.size()!=0){
		printf("1\n");
			printf("%d\n",x);
	}
	else if(resSum.size()!=0){
		printf("1\n");
		printf("%d\n",v[resSum[0].st]+x);
	}
	else if(resDiff.size()!=0){
		FOR(j,0,resDiff.size()){
			int b1 = v[resDiff[j].st];
			int b2 = v[resDiff[j].nd];
			if(b1-x>=0){
				printf("1\n");
				printf("%d\n",b1-x);
				return 0;
			}
			if(b2+x<=l){
				printf("1\n");
				printf("%d\n",b2+x);
				return 0;
			}
		}
		printf("2\n");
		printf("%d %d\n",x,y);		
		return 0;


	}
	else{
		printf("2\n");
		printf("%d %d\n",x,y);		
		return 0;

	}

}