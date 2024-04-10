#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>
#include <stack>

using namespace std;

typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    vector <string> logins;
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            logins.push_back(s1.substr(0, i) + s2.substr(0, j));
        }
    }
    sort(logins.begin(), logins.end());
    cout << logins[0] << endl;
}