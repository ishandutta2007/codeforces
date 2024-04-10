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
	char s[100005];
	scanf("%s",s);
	int n = strlen(s);
	FOR(i,0,n) if(s[i]!=s[n-1-i]){
		printf("NO\n");
		return 0;
	}
	char x[]={'A','H','I','M','O','T','U','V','W','X','Y'};
	FOR(i,0,n){
		bool flaga = false;
		FOR(j,0,11){
			if(s[i]==x[j]){
				flaga = true;
				break;
			}
		}
		if(!flaga){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");


	return 0;
}