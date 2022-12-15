#include <bits/stdc++.h>
using namespace std;




int main() {
    map<string, int> myset;
    int n;
    string s;
    cin >> n;
    while(n--) {
        cin >> s;
        int r = myset[s]++;
        if(r != 0) {
            cout << s + to_string(r) << endl;
        } else {
            puts("OK");
        }
    }
    return 0;
}