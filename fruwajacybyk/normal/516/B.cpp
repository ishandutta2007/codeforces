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

int n,m;
char s[2005][2005];
int byl[2005][2005];
int deg[2005][2005];
int mate[2005][2005];

int dx[]={1,0,0,-1};
int dy[]={0,-1,1,0};
char sg[]={'^','>','<','v'};

bool check(int a,int b){
	return (a>=0 && a<n && b>=0 && b < m && s[a][b]=='.');
}



int main(){
	read2(n,m);
	FOR(i,0,n) scanf("%s",s[i]);
	FOR(i,0,n) FOR(j,0,m) mate[i][j] = -1;
	
	FOR(i,0,n) FOR(j,0,m) deg[i][j] = 0;
	FOR(i,0,n) FOR(j,0,m) FOR(k,0,4) 
		if(s[i][j]!='.') continue;
	  else if(check(i+dx[k],j+dy[k])) deg[i][j]++;
	
	vector<PII> kju;

	FOR(i,0,n) FOR(j,0,m){
		if(s[i][j]=='.' && deg[i][j]==0){
			printf("Not unique\n"); return 0;
		}
		if(s[i][j]=='.' && deg[i][j]==1){
			kju.pb(mp(i,j));
		}
	}
	int i = 0;
	while(1){
		if(i >= kju.size()) break;
		int ax = kju[i].st, ay = kju[i].nd;
		i++;
		if(mate[ax][ay]!=-1) continue;
		int bx = -1,by =-1;
		bool ok = false;
		FOR(j,0,4){
			bx = ax+dx[j], by = ay+dy[j];
			if(check(bx,by) && mate[bx][by]==-1){
				mate[ax][ay] = j;
				mate[bx][by] = 3-j;
				ok = true;
				break;
			}
		}
		if(!ok){
			printf("Not unique\n"); return 0;
		}
		FOR(j,0,4){
			int cx = bx+dx[j], cy = by+dy[j];
			if(check(cx,cy) && mate[cx][cy]==-1){
				deg[cx][cy]--;
				if(deg[cx][cy]==1) kju.pb(mp(cx,cy));
			}
		}
	}
	FOR(i,0,n) FOR(j,0,m){
		if(s[i][j]=='.' && mate[i][j]==-1){ 
			printf("Not unique\n"); return 0;
		}
	}	
	FOR(i,0,n){
		FOR(j,0,m){
			if(s[i][j]!='.') printf("%c",s[i][j]);
			else printf("%c",sg[mate[i][j]]);
		}
		printf("\n");
	}
}