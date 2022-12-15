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
#define max_n 100005

using namespace std;

	int tab[1005][1005];
	lint bR[1000005];
	lint bC[1000005];

int main(){
	int n,m,p,k;

	scanf("%d%d%d%d",&n,&m,&k,&p);

	FOR(i,0,n) FOR(j,0,m) scanf("%d",&tab[i][j]);
	
	multiset<lint> rows,columns;
	FOR(i,0,n){
		lint a = 0LL;
		FOR(j,0,m) a+=tab[i][j];
		rows.insert(-a);
	}

	FOR(j,0,m){
		lint a = 0LL;
		FOR(i,0,n) a+=tab[i][j];
		columns.insert(-a);
	}


	bR[0] = 0LL;
	FOR(i,1,k+1){
		lint x = - (*rows.begin());
		rows.erase(rows.begin());
		bR[i]=bR[i-1]+x;
		x-=(m)*1LL*p;
		rows.insert(-x);
	}

	bC[0] = 0LL;
	FOR(i,1,k+1){
		lint x = - (*columns.begin());
		columns.erase(columns.begin());
		bC[i]=bC[i-1]+x;
		x-=(n)*1LL*p;
		columns.insert(-x);
	}

	lint best = bR[k];
	FOR(i,0,k+1){
		best = max(best, bR[i]+bC[k-i]-(i*1LL*(k-i))*1LL*p);
	}

	cout<<best<<endl;

	

	
	






	return 0;
}