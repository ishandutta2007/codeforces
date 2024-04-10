//#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int DIST = 20000;

int main() {
    int n, where = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        string s;
        cin >> x >> s;
        if (s[0] == 'E' || s[0] == 'W')
            if (where == 0 || where == DIST) {
                cout << "NO\n";
                return 0;
            }
            else
                continue;
        if (s[0] == 'N' && where == 0) {
            cout << "NO\n";
            return 0;
        }
        if (s[0] == 'S' && where == DIST) {
            cout << "NO\n";
            return 0;
        }
        if (s[0] == 'N')
            if (x > where) {
                cout << "NO\n";
                return 0;
            }
            else
                where -= x;
        else
            if (x + where > DIST) {
                cout << "NO\n";
                return 0;
            }
            else
                where += x;
    }
    if (where) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    return 0;
}