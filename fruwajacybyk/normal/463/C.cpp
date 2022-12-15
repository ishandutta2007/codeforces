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


lint tab[2005][2005];

lint s[5000][2];

int main(){
	IOS;
	make(n);
	FOR(i,0,n) FOR(j,0,n){
		make(a); tab[i][j] = a;
	}

	FOR(i,0,n+1) FOR(j,0,5) s[i][j] = 0;

	FOR(i,0,n){
		FOR(j,0,n){
			s[i+j][0] += tab[i][j];
			s[i-j+n][1]+=tab[i][j];
		}
	}
	lint b[2]; 
	b[0] = b[1] = 0;
	PII p[2];
	FOR(i,0,n)
		FOR(j,0,n){
			b[(i+j)%2] = max( b[(i+j)%2], s[i+j][0]+s[i-j+n][1]-tab[i][j]); 
			if(b[(i+j)%2]==s[i+j][0]+s[i-j+n][1]-tab[i][j]) p[(i+j)%2]=mp(i,j);
		}
	cout<<b[0]+b[1]<<endl;
	FOR(i,0,2){
		cout<<p[i].st+1<<" "<<p[i].nd+1<<" ";
	}
	cout<<endl;

	


	return 0;
}