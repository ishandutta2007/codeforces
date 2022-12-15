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
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int res = 100;
	res = min(res,a);
	res = min(res,b);
	res = min(res,c/2);
	res = min(res,d/7);
	res = min(res,e/4);
	cout<<res<<endl;
	return 0;
}