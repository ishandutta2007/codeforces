//CF#175Div2 by HIR180
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
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=k+1;i>=1;i--){
		printf("%d ",i);
	}
	for(int j=k+2;j<=n;j++){
		printf("%d%c",j,j==n?'\n':' ');
	}
}