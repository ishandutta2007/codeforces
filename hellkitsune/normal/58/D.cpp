#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ms
{
    string s;
    int id;
};

bool operator < (const ms &a, const ms &b)
{
    return a.s < b.s;
}

vector<ms> sv, msv[11];
string s;
int n, lenmin = 11, lenmax = 0;
bool used[10000] = {false};

int main(void)
{
    int i;
    cin >> n;
    sv.reserve(n);
    for (i = 0; i < n; ++i)
    {
        cin >> s;
        if ((int)s.length() > lenmax)
            lenmax = s.length();
        if ((int)s.length() < lenmin)
            lenmin = s.length();
        ms sid = {s, i};
        sv.push_back(sid);
        msv[s.length()].push_back(sid);
    }
    cin >> s;
    for (i = 0; i < n; ++i)
        sv[i].s.append(s);
    sort(sv.begin(), sv.end());
    for (i = 1; i <= 10; ++i)
    {
        sort(msv[i].begin(), msv[i].end());
        reverse(msv[i].begin(), msv[i].end());
    }
    lenmax = lenmax + lenmin;
    for (i = 0; i < n; ++i)
        if (!used[sv[i].id])
        {
            cout << sv[i].s;
            used[sv[i].id] = true;
            lenmin = lenmax - sv[i].s.length() + 1;
            while (used[msv[lenmin].back().id])
                msv[lenmin].pop_back();
            cout << msv[lenmin].back().s << '\n';
            used[msv[lenmin].back().id] = true;
            msv[lenmin].pop_back();
        }
    return 0;
}