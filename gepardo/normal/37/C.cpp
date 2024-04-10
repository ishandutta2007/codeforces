#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string next(string s)
{
    if (s == "?") return "0";
    int nZero = -1;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '0') nZero = i;
    if (nZero < 0) return "?";
    s[nZero] = '1';
    for (int i = nZero + 1; i < s.length(); i++) s[i] = '0';
    return s;
}

int main()
{
    int n; cin >> n;
    vector <string> ans(n);
    string cur = "?";
    vector < pair<int,int> > v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        cur = next(cur);
        if (cur == "?") { cout << "NO"; return 0; }
        while (cur.length() < v[i].first) cur += "0";
        ans[v[i].second] = cur;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}