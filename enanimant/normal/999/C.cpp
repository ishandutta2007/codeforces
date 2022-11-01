// July 2, 2018
// http://codeforces.com/contest/999/problem/C

#include <bits/stdc++.h>

using namespace std;


int N, K;
string s;

int letters[26];

int main() {
    cin >> N >> K;
    cin >> s;

    for (char c : s) {
        letters[c - 'a']++;
    }

    int r = 0, extra;
    int first_unblocked_char = 27;
    for (int i = 0; i < 26; i++) {
        r += letters[i];
        if (r > K) {
            extra = K + letters[i] - r;
            first_unblocked_char = i;
            break;
        }
    }

    for (char ch : s) {
        int c = ch - 'a';
        if (c < first_unblocked_char) {
            continue;
        } else if (c == first_unblocked_char) {
            if (extra > 0) {
                extra--;
                continue;
            } else {
                cout << ch;
            }
        } else {
            cout << ch;
        }
    }

    cout << '\n';


    return 0;
}