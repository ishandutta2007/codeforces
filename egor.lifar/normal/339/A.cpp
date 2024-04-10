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
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n - 2; i++){
		for(int j = i + 2; j < n; j++){
			if(s[j] >= '0' && s[j] <= '9' && s[i] <= '9' && s[i] >= '0' && s[j] < s[i]){
				char c = s[i];
				s[i] = s[j];
				s[j] = c;
			}
		}
	}
	cout << s << "\n";
	return 0;
}