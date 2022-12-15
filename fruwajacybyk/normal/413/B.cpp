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
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ch[20005][13];
	FOR(i,0,n){
		FOR(j,0,m){
			int u; scanf("%d",&u);
			ch[i][j] = u;
		}
	}
	int noti[13]; FOR(i,0,m) noti[i]=0;
	int guy[20005]; FOR(i,0,n) guy[i] = 0;
	FOR(i,0,k){
		int u,v; scanf("%d%d",&u,&v);
		u--; v--;
		noti[v]++;
		guy[u]--;
	}
	FOR(i,0,n){
		FOR(j,0,m) if(ch[i][j]) guy[i]+=noti[j];
	}

	FOR(i,0,n) printf("%d ",guy[i]);
	printf("\n");



	return 0;
}