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
#define max_n 1000005
using namespace std;


int t[max_n];
int ile = 1000000;


int main(){
	int n;
	scanf("%d",&n);
	FOR(i,0,max_n) t[i] = 0;
	FOR(i,0,n){
		int u;
		scanf("%d",&u);
		t[u] = 1;
	}
	
	vector<int> puste;
	vector<int> pol;
	vector<int> pelne;

	FOR(i,1,ile+1){
		if(i>ile+1-i) break;
		if(t[i]==1 && t[ile+1-i]==1) pelne.pb(i);
		if(t[i]==1 && t[ile+1-i]==0) pol.pb(i);
		if(t[i]==0 && t[ile+1-i]==1) pol.pb(ile+1-i);
		if(t[i]==0 && t[ile+1-i]==0) puste.pb(i);
	}
	printf("%d\n",n);
	FOR(i,0,pol.size()) printf("%d ",ile+1-pol[i]);
	FOR(i,0,pelne.size()) printf("%d %d ",puste[i],ile+1-puste[i]);
	printf("\n");




	return 0;
}