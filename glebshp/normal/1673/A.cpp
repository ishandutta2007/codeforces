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

    int tests;
    cin >> tests;
    for (int t = 0; t < tests; t++) {
        string s;
        cin >> s;

        int sum = 0;
        for (auto& c : s) {
            sum += int(c) - int('a') + 1;
        }
        int fst = int(s[0]) - int('a') + 1;
        int lst = int(s.back()) - int('a') + 1;

        if (int(s.size()) % 2 == 0) {
            cout << "Alice " << sum << endl;
        } else {
            if (s.size() == 1u) {
                cout << "Bob " << sum << endl;
            } else {
                cout << "Alice " << sum - min(fst, lst) * 2 << endl;
            }
        }
    }

    return 0;
}