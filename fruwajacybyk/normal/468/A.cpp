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
#define all(x) x.begn(),x.end()

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


#define max_n 2000005


using namespace std;



int main(){
	IOS;
	make(n);
	if(n<4){
		printf("NO\n");
		return 0;
	}
	else{
		printf("YES\n");
		if(n%4==0){
			printf("1 + 2 = 3\n3 + 3 = 6\n6 * 4 = 24\n");
			for(int i=5;i<n;i+=4){
				printf("%d + %d = %d\n",i,i+3,2*i+3);
				printf("%d + %d = %d\n",i+1,i+2,2*i+3);
				printf("%d - %d = %d\n",2*i+3,2*i+3,0);
				printf("24 + 0 = 24\n");
			}
		}
		if(n%4==1){
			printf("5 * 4 = 20\n20 + 3 = 23\n23 + 2 = 25\n25 - 1 = 24\n");
			for(int i=6;i<n;i+=4){
				printf("%d + %d = %d\n",i,i+3,2*i+3);
				printf("%d + %d = %d\n",i+1,i+2,2*i+3);
				printf("%d - %d = %d\n",2*i+3,2*i+3,0);
				printf("24 + 0 = 24\n");
			}
		}
		if(n%4==2){
			printf("1 + 3 = 4\n2 * 5 = 10\n4 + 6 = 10\n10 + 10 = 20\n20 + 4 = 24\n");
			for(int i=7;i<n;i+=4){
				printf("%d + %d = %d\n",i,i+3,2*i+3);
				printf("%d + %d = %d\n",i+1,i+2,2*i+3);
				printf("%d - %d = %d\n",2*i+3,2*i+3,0);
				printf("24 + 0 = 24\n");
			}
		}
		if(n%4==3){
			printf("1 + 3 = 4\n4 - 2 = 2\n2 + 5 = 7\n7 + 6 = 13\n13 + 7 = 20\n20 + 4 = 24\n");
			for(int i=8;i<n;i+=4){
				printf("%d + %d = %d\n",i,i+3,2*i+3);
				printf("%d + %d = %d\n",i+1,i+2,2*i+3);
				printf("%d - %d = %d\n",2*i+3,2*i+3,0);
				printf("24 + 0 = 24\n");
			}
		}
	}
	return 0;
}