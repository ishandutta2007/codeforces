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
        map <char, vector <int>> charpos;
        cin >> s;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            charpos[s[i]].pb(i);
        }
        bool strgood = true;

        for (char c = 'a'; c <= 'z'; c++) {
            if (!charpos[c].empty()) {
                for (int i = 0; i < (int) charpos[c].size() - 1; i++) {
                    int str = charpos[c][i];
                    int fns = charpos[c][i + 1];
                    for (char h = 'a'; h <= 'z'; h++) {
                        if (!charpos[h].empty() && h != c) {
                            bool has = false;
                            for (int j = str + 1; j < fns; j++) {
                                if (s[j] == h) {
                                    has = true;
                                    break;
                                }
                            }

                            if (!has) {
                                strgood = false;
                            }
                        }
                    }
                }
            }
        }

        if (strgood) {
            cout << "YES" << endl;            
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}