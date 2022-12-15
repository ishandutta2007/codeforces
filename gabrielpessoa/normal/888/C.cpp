#include <bits/stdc++.h>
using namespace std;

bool isValid(string &s, int k, char c) {
    int qnt = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == c) {
            qnt++;
        }
    }
    bool valid = qnt != 0;
    //if(valid) cout << "oi" << endl;
    for(int i = k; i < s.size(); i++) {
        if(s[i-k] == c) {
            qnt--;
        }
        if(s[i] == c) {
            qnt++;
        }
        if(qnt == 0) {
            valid = false;
        }
    }
    return valid;
}

bool check(string &s, int k) {
    for(char c = 'a'; c <= 'z'; c++) {
        if(isValid(s, k, c)) return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    int l = 1, r = s.size();
    while(l < r) {
        int m = (l+r)/2;
        if(check(s, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;
}