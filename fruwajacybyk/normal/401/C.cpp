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
	int n, m;
	scanf("%d%d",&n,&m);
	if(m-2>2*n){
		printf("-1\n");
		return 0;
	}
	if(n>m+1){
		printf("-1\n");
		return 0;
	}
	if(n==m+1){
		printf("0");
		FOR(i,0,m) printf("10");
		printf("\n");
		return 0;
	}
	while(m>n && n>0){
		printf("110");
		m-=2;
		n--;
	}
	if(m==n){
		while(m--) printf("10");
		printf("\n");
		return 0;
	}
	if(n==0){
		FOR(i,0,m) printf("1");
		printf("\n");
		return 0;
	}
	
	



	return 0;
}