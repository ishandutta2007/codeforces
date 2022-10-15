#include <iostream>
#include <algorithm>

using namespace std;

char mirror[] = "8??3694705";

int main() {
    string s; cin >> s;
    string s2 = s; reverse(s2.begin(), s2.end());
    for (char& c: s2) {
        c = mirror[c - '0'];
    }
    cout << (s == s2 ? "Yes" : "No") << endl;
    return 0;
}