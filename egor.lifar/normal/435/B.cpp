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


string s;
int k;


int main(){
	cin >> s >> k;
	int n = s.size();
    for (int i = 0; i < n; i++) {
    	char c = s[i];
    	int a = 0;
		for (int j = i + 1; j < n; j++) {
			if (s[j] > c && j - i <= k) {
				c = s[j];
				a = j;
			}
 		}
 		for (int j = a; j > i; j--) {
 			swap(s[j], s[j - 1]);
 		}
 		if (a == 0) {
 			continue;
 		}
 		k -= (a - i);
    }
	cout << s << endl;
    return 0;
}