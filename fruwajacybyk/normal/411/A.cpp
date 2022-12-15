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
	char s[105];
	scanf("%s",s);
	int n = strlen(s);
	int x = 0;
	if(n<5) x--;
	FOR(i,0,n){
		if(s[i]>='a' && s[i]<='z'){
			x++;
			break;
		}
	}
	FOR(i,0,n){
		if(s[i]>='A' && s[i]<='Z'){
			x++;
			break;
		}
	}
	FOR(i,0,n){
		if(s[i]>='0' && s[i]<='9'){
			x++;
			break;
		}
	}
	if(x==3) printf("Correct\n");
	else printf("Too weak\n");
	return 0;
}