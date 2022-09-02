#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
int back[100005];
int next[100005];
int main(){
	int n,k;
	int res=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		res+=(b-a+1);
	}
	int gu=res%k;
	printf("%d\n",(k-gu)%k);
}