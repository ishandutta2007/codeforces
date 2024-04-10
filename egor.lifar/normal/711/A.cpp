#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>


using namespace std;


int n;
string s[1001];


int main() {
    cin >> n;
    bool good = 0;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (!good && s[i][0] == 'O' && s[i][1] == 'O') {
            good = 1;
            s[i][0] = '+';
            s[i][1] = '+';
        }
        if (!good && s[i][3] == 'O' && s[i][4] == 'O') {
            good = 1;
            s[i][3] = '+';
            s[i][4] = '+';
        }
    }
    if (good) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << s[i] << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}