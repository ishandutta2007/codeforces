#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int d = min(a, b);
	for(int i = 0; i <= d; i++){
		if(c == a - i + b - i){
			printf("%d %d %d\n", i, b - i, a - i);
			return 0;
		}
	}
	printf("Impossible\n");
	return 0;
}