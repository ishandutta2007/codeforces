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
	int n,m,mini,maxi;
	scanf("%d%d%d%d",&n,&m,&mini,&maxi);
	VI t;
	FOR(i,0,m){
		int u; scanf("%d",&u);
		t.pb(u);
	}
	sort(t.begin(),t.end());
	if(mini>t[0] || maxi<t[m-1]){
		printf("Incorrect\n");
	}
	else{
		if(n-m>1){ 
			printf("Correct\n");
		}
		else{
			if(mini==t[0] || maxi ==t[m-1])
				printf("Correct\n");
			else printf("Incorrect\n");
		}
	}

	return 0;
}