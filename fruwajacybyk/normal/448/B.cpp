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


int main(){
	char s[105],t[105];
	scanf("%s",s);
	scanf("%s",t);
	int n1 = strlen(s);
	int n2 = strlen(t);
	
	int c1[30];
	int c2[30];
	FOR(i,0,30) c1[i]= c2[i] = 0;

	FOR(i,0,n1) c1[s[i]-'a']++;
	FOR(i,0,n2) c2[t[i]-'a']++;
	


	FOR(i,0,30){
		if(c1[i]<c2[i]){
			printf("need tree\n");
			return 0;
		}
	}

	if(n1==n2){
		printf("array\n");
		return 0;
	}

	int j = 0;
	int i = 0;
	while(j!=n2 && i!=n1){
		if(s[i]==t[j]){
			i++; j++;
		}
		else i++;
	}
	if(j==n2){
		printf("automaton\n");
		return 0;
	}
	printf("both\n");
	


	



	return 0;
}