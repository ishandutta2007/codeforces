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

using namespace std;

int b[8];
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		b[a] += 1;
	}
	if(b[5] != 0 || b[7] != 0){
		printf("-1\n");
		return 0;
	}
	if(!(b[2] + b[3] == b[1] && b[6] + b[4] == b[1] && b[2] >= b[4] && b[1] >= b[4])){
		printf("-1\n");
		return 0;
	}
	b[2] -= b[4];
	b[1] -= b[4];
	if(!(b[6] == b[1] && b[2] + b[3] == b[6])){
		printf("-1\n");
		return 0;
	}
	for(int i = 0; i < b[4]; i++){
		printf("1 2 4\n");
	}
	for(int i = 0; i < b[3]; i++){
		printf("1 3 6\n");
	}
	for(int i = 0; i < b[2]; i++){
		printf("1 2 6\n");
	}
	return 0;
}