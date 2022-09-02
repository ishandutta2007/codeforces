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
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%d\n",min(n,m)+1);
	if(n>=m){
		for(int i=0;i<m+1;i++){
			printf("%d %d\n",i,m-i);
		}
	}else{
		for(int i=n;i>=0;i--){
			printf("%d %d\n",i,n-i);
		}
	}
}