#include <bits/stdc++.h>
using namespace std;

int n;
string str1, str2;

int main() {
    cin >> str1 >> str2 >> n;
    cout << str1 << " " << str2 << endl;
    while (n--) {
        string s, t;
        cin >> s >> t;
        if (str1 == s) str1 = t;
        else str2 = t;
        cout << str1 << " " << str2 << endl;
    }
    return 0;
}