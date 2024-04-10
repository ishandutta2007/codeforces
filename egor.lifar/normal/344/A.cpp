#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 

using namespace std;

int main() {
	int n;
	cin >> n;
	string s[100000];
	int k = 0;
	char c = '2';
	for(int i = 0; i < n; i++){
		cin >> s[i];
		if(s[i][0] == c || c == '2'){
			k++;
		}
		c = s[i][1];
	}
	printf("%d\n", k);
	return 0;
}