#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int ans=0;
	int left=0;
	for(int i=0; i < n; ++i){
		int a;
		scanf("%d", &a);
		if(left < a){
			left=m;
			++ans;
		}
		left -= a;
	}
	printf("%d\n", ans);
	return 0;
}