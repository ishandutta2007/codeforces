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
	int n,m;
	scanf("%d%d",&n,&m);
	char s[1005][1005];
	FOR(i,0,n) scanf("%s",s[i]);
	set<int> secik;
	FOR(i,0,n){
		int g = -1,c = -1;
		FOR(j,0,m){
			if(s[i][j]=='G') g = j;
			if(s[i][j]=='S') c = j;
		}
		if(c<g){
			printf("-1\n");
			return 0;
		}
		secik.insert(c-g);
	}
	printf("%d\n",secik.size());

	return 0;
}