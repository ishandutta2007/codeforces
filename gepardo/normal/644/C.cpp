#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair < pair<int,int>, pair<int,int> > strHash;

template <typename T1, typename T2>
ostream& operator<<(ostream& os, pair<T1,T2> p) { os << "{" << p.first << ", " << p.second << "}"; return os; }

strHash getHash(string s)
{
    long long h1 = 0, h2 = 0, h3 = 0, h4 = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
        h1 = (h1 * 1234570189 + s[i]) % 1895827441,
        h2 = (h2 * 1282565129 + s[i]) % 1819999999,
        h3 = (h3 * 1020304049 + s[i]) % 1959991567,
        h4 = (h4 * 1110636799 + s[i]) % 1760540351;
    return {{h1, h2}, {h3, h4}};
}

pair <string,string> parse(string s)
{
    s.erase(0, 7); //Erase "http://"
    int pos = s.find("/");
    if (pos == string::npos) return {s, ""};
        else return {s.substr(0, pos), s.substr(pos, s.length() - pos)};
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector < pair<string,string> > v(n);
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        v[i] = parse(s);
    }
    sort(v.begin(), v.end());
    vector <string> strs;
    vector < pair<string,int> > pairs;
    strs.push_back(v[0].first);
    pairs.push_back({v[0].second, 0});
    for (int i = 1; i < n; i++)
        if (v[i].first == v[i - 1].first)
        {
            if (v[i].second != v[i - 1].second)
                pairs[pairs.size() - 1].first += "+" + v[i].second;
        }
        else
        {
            strs.push_back({v[i].first});
            pairs.push_back({v[i].second, strs.size() - 1});
        }
    vector < pair<strHash,int> > hashed;
    for (int i = 0; i < pairs.size(); i++) hashed.push_back({getHash(pairs[i].first), pairs[i].second});
    sort(hashed.begin(), hashed.end());
    vector<string> groups;
    int lastGroupSize = 1; string lastGroup = "http://" + strs[hashed[0].second];
    for (int i = 1; i < hashed.size(); i++)
        if (hashed[i].first != hashed[i - 1].first)
        {
            if (lastGroupSize > 1) groups.push_back(lastGroup);
            lastGroupSize = 1;
            lastGroup = "http://" + strs[hashed[i].second];
        }
        else
        {
            lastGroup += " http://" + strs[hashed[i].second];
            lastGroupSize++;
        }
    if (lastGroupSize > 1) groups.push_back(lastGroup);
    cout << groups.size() << endl;
    for (int i = 0; i < groups.size(); i++) cout << groups[i] << endl;
}