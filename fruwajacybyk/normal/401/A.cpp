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
	int n,x;
	scanf("%d%d",&n,&x);
	int sum = 0;
	FOR(i,0,n){
		int u;
		scanf("%d",&u);
		sum += u;
	}
	sum = max(sum,-sum);
	printf("%d\n",(sum+(x-1))/x);
}