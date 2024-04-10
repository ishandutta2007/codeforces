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

const int maxlen = 1500 * 1000 + 100;

int a, b, c, d;
char str[maxlen];
int n;

bool checkCount() {
    int acnt = a + c + d, bcnt = b + c + d;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            acnt--;
        }
        if (str[i] == 'B') {
            bcnt--;
        }
    }

    return (acnt == 0 && bcnt == 0);
}

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    scanf("%d", &tnum);

    for (int tc = 0; tc < tnum; tc++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        scanf("%s", str);

        n = strlen(str);

        if (!checkCount()) {
            printf("NO\n");
            continue;
        }

        vector <int> odds;
        vector <int> evensa;
        vector <int> evensb;

        
        int i = 0;
        int j = 0;
        while (i < n) {
            while (j < n && (j == i || str[j] != str[j - 1])) {
                j++;
            }

            if (j - i == 1) {
                if (str[i] == 'A') {
                    a--;
                }    
                if (str[i] == 'B') {
                    b--;
                }
            } else {
                if ((j - i) % 2 == 1) {
                    if (str[i] == 'A') {
                        a--;
                    } else {
                        b--;
                    }
                    odds.pb((j - i) / 2);
                } else {
                    if (str[i] == 'A') {
                        evensa.pb((j - i) / 2);
                    } else {
                        evensb.pb((j - i) / 2);
                    }
                }
            }

            i = j;
        }

        if (a < 0 || b < 0) {
            printf("NO\n");
            continue;
        }

        sort(evensa.rbegin(), evensa.rend());
        sort(odds.begin(), odds.end());
        sort(evensb.begin(), evensb.end());
        while (c > 0) {
            if (!evensa.empty()) {
                int t = min(evensa.back(), c);
                c -= t;
                evensa[(int) evensa.size() - 1] -= t;
                if (evensa.back() == 0) {
                    evensa.pop_back();
                }

                continue;
            }
            if (!odds.empty()) {
                int t = min(odds.back(), c);
                c -= t;
                odds[(int) odds.size() - 1] -= t;
                if (odds.back() == 0) {
                    odds.pop_back();
                }

                continue;
            }
            if (!evensb.empty() && evensb.back() > 1) {
                int t = min(evensb.back() - 1, c);
                c -= t;
                a--;
                b--;
                evensb[(int) evensb.size() - 1] -= (t + 1); 
                if (evensb.back() == 0) {
                    evensb.pop_back();
                }

                continue;
            }

            break;
        }

        sort(evensa.begin(), evensa.end());
        sort(odds.begin(), odds.end());
        sort(evensb.rbegin(), evensb.rend());
        while (d > 0) {
            if (!evensb.empty()) {
                int t = min(evensb.back(), d);
                d -= t;
                evensb[(int) evensb.size() - 1] -= t;
                if (evensb.back() == 0) {
                    evensb.pop_back();
                }

                continue;
            }
            if (!odds.empty()) {
                int t = min(odds.back(), d);
                d -= t;
                odds[(int) odds.size() - 1] -= t;
                if (odds.back() == 0) {
                    odds.pop_back();
                }

                continue;
            }
            if (!evensa.empty()&& evensa.back() > 1) {
                int t = min(evensa.back() - 1, d);
                d -= t;
                a--;
                b--;
                evensa[(int) evensa.size() - 1] -= (t + 1); 

                if (evensa.back() == 0) {
                    evensa.pop_back();
                }

                continue;
            }

            break;
        }

        if (a < 0 || b < 0 || c > 0 || d > 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}