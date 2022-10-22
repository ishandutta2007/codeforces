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
	int n;
	int p=0;
	int ans=0;
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int r;
		scanf("%d", &r);
		if(r == -1){
			if(p)
				--p;
			else
				++ans;
		}
		else
			p += r;
	}
	printf("%d\n", ans);
	return 0;
}