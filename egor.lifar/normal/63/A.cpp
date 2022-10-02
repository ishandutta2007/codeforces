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


using namespace std;


int main() {
    int n;
    pair<string, string> s[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        s[i] = make_pair(a, b);
    }
    for (int i = 0; i < n; i++) {
        if(s[i].second == "rat") {
            cout << s[i].first << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        if(s[i].second == "woman" || s[i].second == "child") {
            cout << s[i].first << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        if(s[i].second == "man") {
            cout << s[i].first << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        if(s[i].second == "captain") {
            cout << s[i].first << endl;
        }
    }
    return 0;
}