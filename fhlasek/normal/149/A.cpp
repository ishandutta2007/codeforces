/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

int K;
int a[13];


int main(int argc, char *argv[]){
	scanf("%d",&K);
	REP(i,12) scanf("%d",a+i);
	sort(a,a+12,greater<int>());
	int sum = 0,i = 0;
	while(sum<K && i<12) sum += a[i++];
	if(sum < K) printf("-1\n");
	else printf("%d\n",i);
	return 0;
}