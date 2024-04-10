
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
	int a[2]={0,0};
	for(int i=0; i < 2; ++i)
		for(int j=0; j < 3; ++j){
			int t;
			scanf("%d", &t);
			a[i] += t;
		}
	int have;
	scanf("%d", &have);
	have -= (a[0]+4)/5;
	have -= (a[1]+9)/10;
	if(have < 0)
		puts("NO");
	else
		puts("YES");
	return 0;
}