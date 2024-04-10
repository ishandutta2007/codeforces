#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <cassert>


using namespace std;


bool goodb[26];
bool goods[26];


int main() {
    string s;
    cin >> s;
    goodb['A' - 'A'] = 1;
    goodb['H' - 'A'] = 1;
    goodb['I' - 'A'] = 1;
    goodb['M' - 'A'] = 1;
    goodb['O' - 'A'] = 1;
    goods['o' - 'a'] = 1;
    goodb['U' - 'A'] = 1;
    goodb['V' - 'A'] = 1;
    goods['v' - 'a'] = 1;
    goodb['W' - 'A'] = 1;
    goods['w' - 'a'] = 1;
    goodb['X' - 'A'] = 1;
    goodb['T' - 'A'] = 1;
    goods['x' - 'a'] = 1;
    goodb['Y' - 'A'] = 1;
    bool good = 1;
    if ((int)s.size() % 2 == 1) {
        int l = (int)s.size() / 2;
        if (s[l] >= 'A' && s[l] <= 'Z') {
            if (!goodb[s[l] - 'A']) {
                good = 0;
            }
        } else {
            if (!goods[s[l] - 'a']) {
                good = 0;
            }
        }
    }
    int l = (int)s.size() / 2;
    for (int i = 0; i < l; i++) {
        if (s[i] == s[(int)s.size() - 1 - i]) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                if (!goods[s[i] - 'a']) {
                    good = 0;
                    break;
                }
            } else {
                if (!goodb[s[i] - 'A']) {
                    good = 0;
                    break;
                }
            }
            continue;
        }
        if (s[i] == 'p' && s[(int)s.size() - 1 - i] == 'q') {
            continue;
        }
        if (s[i] == 'q' && s[(int)s.size() - 1 - i] == 'p') {
            continue;
        }
        if (s[i] == 'b' && s[(int)s.size() - 1 - i] == 'd') {
            continue;
        }
        if (s[i] == 'd' && s[(int)s.size() - 1 - i] == 'b') {
            continue;
        }
        good = 0;
        break;
    } 
    if (good) {
        cout << "TAK" << endl; 
    } else {
        cout << "NIE" << endl;
    }
    return 0;
}