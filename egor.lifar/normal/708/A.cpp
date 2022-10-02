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
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>


using namespace std;


int n;
string s;


int main() {
    cin >> s;
    n = (int)s.size();
    bool b = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] != 'a') {
            int l = i;
            while (l < n && s[l] != 'a') {
                s[l]--;
                l++;
            }
            b = 0;
            break;  
        }
    }
    if (b) {
        s[n - 1] = 'z';
    }
    cout << s << endl;
    return 0;
}