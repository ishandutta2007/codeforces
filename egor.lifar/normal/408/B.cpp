#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


string s, s1;


map<char, int> m, m1;


int main() {
    cin >> s >> s1;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
    }
    for (int i = 0; i < s1.size(); i++) {
        m1[s1[i]]++;
    }
    int ans = 0;
    for (char i = 'a'; i <= 'z'; i++) {
        if (m[i] == 0 && m1[i] != 0) {
            cout << -1 << endl;
            return 0;
        }
        ans += min(m[i], m1[i]);
    }
    cout << ans << endl;
	return 0;
}