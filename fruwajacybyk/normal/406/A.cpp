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

int mat[1005][1005];

int main(){
	int n;
	scanf("%d",&n);
	FOR(i,0,n){
		FOR(j,0,n){
			scanf("%d",&mat[i][j]);
		}
	}
	int akt = 0;
	FOR(i,0,n) akt = (akt+mat[i][i])%2;
	
	int q;
	scanf("%d",&q);
	FOR(i,0,q){
		int nr;
		scanf("%d",&nr);
		if(nr==1 || nr==2){
			akt = 1-akt;
			int x; scanf("%d",&x);
		}
		else printf("%d",akt);
	}
	printf("\n");


	return 0;
}