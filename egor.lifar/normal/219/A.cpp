
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

map<int, int> m;
int main() {
	int k;
	string s;
	cin >> k >> s;
	int n = s.size();
    for(int i = 0; i < 26; i++){
    	m['a' + i] = 0;
    }
	for(int i = 0; i < n; i++){
		m[s[i]] += 1;
	}
	string s2;
	for(int i = 0; i < 26; i++){
    	if(m['a' + i] % k != 0){
    		printf("-1\n");
    		return 0;
    	}
   		for(int j = 0; j < m['a' + i] / k; j++){
    		s2 += 'a' + i;
    	}

    }
    for(int i = 0; i < k; i++){
    	cout << s2;
    }
    cout << "\n";
	return 0;
}