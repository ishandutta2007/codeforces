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
#define max_n 1000005

int maxL[max_n];
int minP[max_n];
int maxS[max_n];

char s[100];
bool zle = false;
int L[max_n];
int P[max_n];

int rob(int v,int lb, int rb){
//	debug3(v,lb,rb);
	if(maxS[v] > rb || lb > rb) return -1;
	if(maxL[v]==-1){
	//	cout<<"C1"<<endl;
		L[v] = -1;
		if(lb==v && maxS[v]==v){
			P[v] = -1;
		//	debug(v);
			return v;
		}
		int w = rob(v+1,max(lb,maxS[v]),rb);
		P[v] = v+1;
		//debug(w);
		return w;
	}
	if(minP[v]==1e9){
		//cout<<"C2"<<endl;
		P[v] = -1;
		int w = rob(v+1,max(lb,maxS[v]),rb);
		L[v] = v+1;
		//debug(w);
		return w;
	}
	//cout<<"C3"<<endl;
	int w = rob(v+1,maxL[v],min(rb,minP[v]-1));
	if(w==-1) { /*debug(w) */; return w;}
	L[v] = v+1;
	int u = rob(w+1,max(lb,maxS[v]), rb); 
	P[v] = w+1;
	//debug(u);
	return u;
}

void inorder(int v){
	if(v==-1) return;
	inorder(L[v]);
	printf("%d ",v);
	inorder(P[v]);
}

int main(){
	make2(n,c);
	FOR(i,0,n+1) maxL[i] = -1;
	FOR(i,0,n+1) minP[i] = 1e9;
	FOR(i,0,n+1) maxS[i] = i;

	FOR(i,0,c){
		make2(x,y);
		scanf("%s",s);
		if(y <= x) zle = true;
		if(s[0]=='L') maxL[x] = max(maxL[x],y);
		if(s[0]=='R') minP[x] = min(minP[x],y);
		maxS[x] = max(maxS[x],y);
	}
	/*FOR(i,1,n+1){
		printf("%d %d %d\n",maxL[i],minP[i],maxS[i]);
	}*/
	
	FOR(i,1,n+1){
		if(maxL[i]!=-1 && minP[i]!=1e9 && maxL[i] >= minP[i]) zle = true;
	}
	if(zle){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	int ans = rob(1,n,n);
	if(ans==-1){
		printf("IMPOSSIBLE\n");
		return 0;
	}
	inorder(1);
	printf("\n");
}