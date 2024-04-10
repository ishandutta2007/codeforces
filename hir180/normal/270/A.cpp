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
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		double we;
		scanf("%lf",&we);
		bool ok=true;
		for(int j=3;j<=360;j++){
			if(we==180.0*(j-2)/j){
				puts("YES");
				ok=false;
			}
		}
		if(ok){
			puts("NO");
		}
	}
}