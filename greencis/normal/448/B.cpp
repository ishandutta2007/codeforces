#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string s1, s2;

bool check(string s, string t) {
    int si = 0, ti = 0;
    while (si < s.size() && ti < t.size()) {
        if (s[si] == t[ti])
            ++ti;
        ++si;
    }
    return ti == t.size();
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> s1 >> s2;
    bool automaton = (s1.size() != s2.size());
    if (check(s1, s2)) {
        cout << "automaton";
        return 0;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (check(s1, s2)) {
        cout << (automaton ? "both" : "array");
        return 0;
    }
    cout << "need tree";

    return 0;
}