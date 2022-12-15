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

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

using namespace std;


int main(){
	int m,n,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<PII> v[105];
	FOR(i,0,n){
		FOR(j,0,m){
			int a; scanf("%d",&a);
			v[j].pb(mp(a,i));
		}
	}
	int locked[105];
	FOR(i,0,n) locked[i] = 0;
	
	int blokowana[105];
	FOR(i,0,k+3) blokowana[i] = -1;
	
	FOR(j,0,m){
		FOR(i,0,n){
			if(v[j][i].st==0) continue;
			int gosc = v[j][i].nd;
			int ktora = v[j][i].st;
			
			if(locked[gosc]==0){
				if(blokowana[ktora]==-1) blokowana[ktora]=gosc;
				else{
					locked[gosc]=j+1;
					if(locked[blokowana[ktora]]==0)
					locked[blokowana[ktora]]=j+1;
				}
			}	
		}
		FOR(i,0,k+3){
			if(blokowana[i]!=-1 && locked[blokowana[i]]==0) blokowana[i] = -1;
		}
	}

	FOR(i,0,n) printf("%d\n",locked[i]);
	


	return 0;
}