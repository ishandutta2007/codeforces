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
using namespace std;

int main(){
	int n, t, c;
	scanf("%d%d%d", &n, &t, &c);
	int good=0;
	int ans=0;
	for(int i=0; i < n; ++i){
		int s;
		scanf("%d", &s);
		if(s > t)
			good=0;
		else{
			++good;
			if(good >= c)
				++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}