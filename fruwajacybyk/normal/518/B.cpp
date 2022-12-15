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

char s[200005], t[200005];

int up[30], dn[30];
int zup[30], zdn[30];

int main(){
	scanf("%s",s);
	scanf("%s",t);
	int n = strlen(s);
	int m = strlen(t);
	FOR(i,0,30) up[i] = dn[i] = zup[i] = zdn[i] = 0;
	FOR(i,0,n){
		if(s[i]>='A' && s[i]<='Z') up[s[i]-'A']++;
		else if(s[i]>='a' && s[i]<='z') dn[s[i]-'a']++;
	}	
	int ans1 = 0, ans2 = 0;
	FOR(i,0,m){
		if(t[i]>='A' && t[i]<='Z'){
			if(up[t[i]-'A']>0){
				ans1++; up[t[i]-'A']--;
			}
			else zup[t[i]-'A']++;
		}
		if(t[i]>='a' && t[i]<='z'){
			if(dn[t[i]-'a']>0){
				ans1++; dn[t[i]-'a']--;
			}
			else zdn[t[i]-'a']++;
		}
	}
	FOR(i,0,30){
		ans2 += min(zup[i],dn[i]);
		ans2 += min(zdn[i],up[i]);
	}
	printf("%d %d\n",ans1,ans2);

}