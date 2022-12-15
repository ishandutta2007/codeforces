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
#define max_n 600005

lint ans1[max_n];
lint ans2[max_n];
int minsufa[max_n];
int maxprefb[max_n];

int res[max_n];

int main(){
	make2(n,w);
	vector<PII> v1;
	vector<pair<PII,int> > v2;
	FOR(i,0,n){
		make2(a,b);
		if(b-a>=a){
			v1.pb(mp(a,-i-1));
			v1.pb(mp(b-a,i+1));
		}
		else{
			v2.pb(mp(mp(b,b-a),i));
		}
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());

	if(v2.size()){
	maxprefb[0] = v2[0].st.nd;
	FOR(i,1,v2.size()){
		maxprefb[i] = max(maxprefb[i-1],v2[i].st.nd);
	}
	minsufa[v2.size()] = 1e9;
	minsufa[v2.size()-1] = v2[v2.size()-1].st.st-v2[v2.size()-1].st.nd;
	FORD(i,v2.size()-2,0){
		minsufa[i] = min(minsufa[i+1],v2[i].st.st-v2[i].st.nd);
	}
	}
	ans1[0] = 0;
	FOR(i,1,v1.size()+1){
		ans1[i] = ans1[i-1]+v1[i-1].st;
	}


	ans2[0] = 0;
	int j = 0; 
	lint pref = 0;
	while(j<v2.size()){
		pref+= v2[j].st.st;
		ans2[2*j+1] = min(pref-maxprefb[j],pref+minsufa[j+1]-v2[j].st.st);
		ans2[2*j+2] = pref;
		j++;
	}

	lint best = 1e9 * 1LL * 1e9;
	int dlak = -1;
	FOR(k,0,w+1){
		int l = w-k;
		if(k<=v1.size() && l <= 2*v2.size()){
			if(ans1[k]+ans2[l]< best){
				best = ans1[k] + ans2[l];
				dlak = k;
			}
		}
	}

	
	cout<<best<<endl;
	FOR(i,0,n) res[i] = 0;
	FOR(i,0,dlak){
		if(v1[i].nd<0) res[-v1[i].nd-1]=1;
		else res[v1[i].nd-1] = 2;
	}

	int l = w-dlak;

	if(l%2==0){
		FOR(j,0,l/2) res[v2[j].nd]=2;
	}
	else{
		if(ans2[l+1]-ans2[l] == maxprefb[l/2]){
			bool ok = false;
			FOR(j,0,l/2+1){
				if(!ok && v2[j].st.nd == maxprefb[l/2]) res[v2[j].nd] = 1, ok = true;
				else res[v2[j].nd] = 2;
			}
		}
		else{
			FOR(j,0,l/2){
				res[v2[j].nd] = 2;
			}
			FOR(j,l/2,v2.size()){
				if(v2[j].st.st-v2[j].st.nd == minsufa[l/2+1]){
					res[v2[j].nd] = 1;
					break;
				}
			}
		}
	}

	FOR(i,0,n) printf("%d",res[i]);
	printf("\n");

	return 0;
}