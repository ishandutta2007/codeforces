#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;

    for (int tc = 0; tc < tnum; tc++) {
        string s;
        cin >> s;

        unordered_map<char, int> lst;
        for (int i = 0; i < (int) s.size(); i++) {
            lst[s[i]] = i;
        }
        int ans = (int) s.size();
        for (auto& e : lst) {
            ans = min(ans, e.sc);
        }

        cout << string(s.begin() + ans, s.end()) << endl;
    }

    return 0;
}