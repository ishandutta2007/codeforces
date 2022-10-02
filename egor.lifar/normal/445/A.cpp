#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <stack>


using namespace std;


int n, m;
string s[100];
string s1[100];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        s1[i] = s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    s1[i][j] = 'B';
                } else {
                    s1[i][j] = 'W';
                }
            }
        }
        cout << s1[i] << endl;
    }
    return 0;
}