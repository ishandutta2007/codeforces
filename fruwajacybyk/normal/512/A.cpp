#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(v) (v).begin(),(v).end()

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
#define makev(v,n) VI (v); FOR(i,0,(n)) { make(a); (v).pb(a);} 
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define readv(v,n) FOR(i,0,(n)) { make(a); (v).pb(a);}

using namespace std;
#define max_n 100005

char s[105][105];
int n;
VI dl;
int les[30][30];


int main(){
	scanf("%d",&n);
	FOR(i,0,n){
		scanf("%s",s[i]);
		dl.pb(strlen(s[i]));
	}
	FOR(i,0,30) FOR(j,0,30) les[i][j] = -1;
	FOR(i,0,n-1){
		int d1 = dl[i], d2 = dl[i+1];
		int dif = -1;
		FOR(j,0,min(d1,d2)){
			if(s[i][j]!=s[i+1][j]){
				dif = j;
				break;
			}
		}
		if(dif!=-1){
			int a = s[i][dif]-'a', b = s[i+1][dif]-'a';
			if(les[a][b]==0){
				printf("Impossible\n");
				return 0;
			}
			else{
				les[a][b] = 1;
				les[b][a] = 0;
			}
		}
		if(dif==-1){
			if(d1 > d2){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	string res="";
	int dupa[30];
	FOR(i,0,30) dupa[i] = 0;
	FOR(i,0,26){
		FOR(j,0,26){
			if(les[i][j]==1) dupa[j]++;
		}
	}
	int byl[30]; 
	FOR(i,0,30) byl[i] = 0;
	while(1){
		int ok = false;
		FOR(i,0,26){
			if(dupa[i]==0 && byl[i]==0){
				res+= ('a'+i);
				byl[i] = 1; 
				FOR(j,0,26) if(les[i][j]==1) dupa[j]--;
				ok = true;
			}
		}
		if(!ok) break;
	}
	if(res.length()!=26){
		printf("Impossible\n");
		return 0;
	}
	cout<<res<<endl;
}