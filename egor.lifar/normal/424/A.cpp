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
#include <assert.h>


using namespace std;



int n;
string s;
int a, b;


int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            a++;
        } else { 
            b++;
        }
    }
    cout << abs(n / 2 - a) << endl;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X' && a < b) {
            s[i] = 'x';
            a++;
            b--;
        }
        if (s[i] == 'x' && a > b) {
            s[i] = 'X';
            a--;
            b++;
        }
    }
    cout << s << endl;
    return 0;
}