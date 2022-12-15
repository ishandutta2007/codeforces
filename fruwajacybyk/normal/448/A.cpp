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
	int a=0,b=0,c,d;
	int n;
	FOR(i,0,3){
		scanf("%d",&c);
		a+=c;
	}
	FOR(i,0,3){
		scanf("%d",&d);
		b+=d;
	}
	scanf("%d",&n);
	int n1 = (a+4)/5;
	int n2 = (b+9)/10;

	if(n>=n1+n2) printf("YES\n");
	else printf("NO\n");



	return 0;
}