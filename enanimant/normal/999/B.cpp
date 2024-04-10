// July 2, 2018
// http://codeforces.com/contest/999/problem/B

#include <bits/stdc++.h>

using namespace std;


int n;
string s;
vector<int> divs;

int main() {
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
        }
    }

    for (int d : divs) {
        reverse(s.begin(), s.begin() + d);
    }

    cout << s << '\n';


    return 0;
}