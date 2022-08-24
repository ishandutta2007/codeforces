#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

int main()
{
    string s;
    string t;
    cin >> s >> t;
    vector<int> a(256);
    for (int i = 0; i < s.length(); i++) a[s[i]]++;
    for (int i = 0; i < t.length(); i++) a[t[i]]--;
    int st = 0;
    for (int i = 0; i < 256; i++){
        if (a[i] < 0) st |= 2; else
            if (a[i] > 0) st |= 1;
    }
    if (st & 2) cout << "need tree\n"; else
    if ((st & 1) == 0) cout << "array\n"; else {
        int j = 0;
        for (int i = 0; i < s.length(); i++){
            if (j < t.length() && t[j] == s[i]) j++;
        }
        if (j == t.length()) cout << "automaton\n"; else cout << "both\n";
    }

    return 0;
}