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

bool check(char* s,int a,int b){

	FOR(i,0,b){
		bool flaga = true;
		FOR(j,0,a) if(s[i+j*b]!='X') flaga = false;
		if(flaga) return true;
	}
	return false;
}

int main(){
	int t; scanf("%d",&t);
	while(t--){
		char s[20]; scanf("%s",s);
		int ile = 0;
		vector<PII> pos;
		FOR(a,1,13){
			if(12%a!=0) continue;
			int b = 12/a;
			if(check(s,a,b)){
				ile++;
				pos.pb(mp(a,b));
			}
		}
		printf("%d ",ile);
		FOR(i,0,pos.size()){
			printf("%dx%d ",pos[i].st,pos[i].nd);
		}
		printf("\n");
	}
	return 0;
}