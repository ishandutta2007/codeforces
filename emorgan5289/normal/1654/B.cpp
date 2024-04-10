#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while (t--) {
 
        string s; cin >> s;
        map<char, int> frequency;
        for (char c : s)
            frequency[c]++;
 
        for (int i = 0; i < s.size(); i++)
            if (--frequency[s[i]] == 0) {
                cout << s.substr(i) << "\n";
                break;
            }
    }
}