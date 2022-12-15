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
	char s[55];
	scanf("%s",s);
	int n; scanf("%d",&n);
	FOR(i,0,strlen(s)){
		int x;
		if( s[i]>='a' && s[i]<='z') x = s[i]-'a';
		else x = s[i]-'A';
	
			if(x<n) putchar('A'+x);
			else putchar('a'+x);
	}
	putchar('\n');
	return 0;
}