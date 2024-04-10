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
	int t;
	scanf("%d",&t);
	while(t--){
		int n,p;
		scanf("%d%d",&n,&p);
		set<PII> edges;
		edges.clear();
		FOR(i,0,n){
			edges.insert(mp(i,(i+1)%n));
			edges.insert(mp(i,(i+2)%n));
		}
		int ile = 0;
		FOR(i,0,n){
			FOR(j,i+1,n){
				if(ile<p){
					if(edges.find(mp(i,j))==edges.end() && edges.find(mp(j,i))==edges.end()){
						ile++;
						edges.insert(mp(i,j));
					}
				}
			}
		}
		for(set<PII>::iterator it = edges.begin();it!=edges.end();it++){
			printf("%d %d\n",(it->st)+1,(it->nd)+1);
		}
	}
	return 0;
}