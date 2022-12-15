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

vector<string> v;

int n;

map<pair<char,char>,int>  names;
set<pair<char,char> > goscie;
vector< pair<char,char> > nr;

VI g[4000];
int indeg[4000];
int outdeg[4000];
stack<int> st;


int main(){
	IOS;
	cin>>n;
	FOR(i,0,n){
		string s; cin>>s;
		if(goscie.find(mp(s[0],s[1]))==goscie.end()){
			goscie.insert(mp(s[0],s[1]));
			nr.pb(mp(s[0],s[1]));
			names[mp(s[0],s[1])] = nr.size()-1;
		}
		if(goscie.find(mp(s[1],s[2]))==goscie.end()){
			goscie.insert(mp(s[1],s[2]));
			nr.pb(mp(s[1],s[2]));
			names[mp(s[1],s[2])] = nr.size()-1;
		}
		g[names[mp(s[0],s[1])]].pb(names[mp(s[1],s[2])]);
	}
	int k = nr.size();
	FOR(i,0,k) outdeg[i] = g[i].size(), indeg[i] = 0;
	FOR(i,0,k) FORE(j,g[i]) indeg[*j]++;
	VI starty, mety;
	FOR(i,0,k){
		if(indeg[i]+1==outdeg[i]) 
			starty.pb(i); 
		if(indeg[i]==outdeg[i]+1)
			mety.pb(i);
		if(indeg[i]-outdeg[i] > 1){
			printf("NO\n"); return 0;
		}
		if(outdeg[i]-indeg[i] > 1){
			printf("NO\n"); return 0;
		}
	}
	if(starty.size() > 1 || mety.size() >1 || starty.size()!=mety.size()){
			printf("NO\n"); return 0;	
	}
	int act;
	VI circut;
	if(starty.size()!=0) act = starty[0];
	else act = 0;


	while(1){
		if(outdeg[act]==0){
			circut.pb(act);
			if(st.empty()) break;
			int v = st.top(); st.pop();
			act = v;
		}
		else{
			st.push(act);
			int w = g[act].back();
			g[act].pop_back();
			outdeg[act]--;
			act = w;
		}
	}
	if(circut.size()!=n+1){
		printf("NO\n"); return 0;
	}
	reverse(all(circut));
	printf("YES\n");
	FOR(i,0,circut.size()){
		putchar(nr[circut[i]].st);
	}
	putchar(nr[circut.back()].nd);

	printf("\n");

	
}