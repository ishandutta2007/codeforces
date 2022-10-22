#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	int sum=0;
	for(int i=0; i < n; ++i){
		int j;
		scanf("%d", &j);
		sum += j;
	}
	if(sum < 0)sum=-sum;
	printf("%d\n", (sum+x-1)/x);
	return 0;
}