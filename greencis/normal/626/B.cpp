#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

string s;
int n;
char dp[205][205][205];

int main()
{
    cin >> n >> s;
    int r = 0, g = 0, b = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == 'R') ++r;
        if (s[i] == 'G') ++g;
        if (s[i] == 'B') ++b;
    }
    queue< pair<int, pii> > q;
    q.push(make_pair(r, make_pair(g, b)));
    while (!q.empty()) {
        r = q.front().first;
        g = q.front().second.first;
        b = q.front().second.second;
        q.pop();
        if (dp[r][g][b]) continue;
        dp[r][g][b] = 1;
        if (r >= 2) q.push(make_pair(r - 1, make_pair(g, b)));
        if (g >= 2) q.push(make_pair(r, make_pair(g - 1, b)));
        if (b >= 2) q.push(make_pair(r, make_pair(g, b - 1)));
        if (r >= 1 && g >= 1) q.push(make_pair(r - 1, make_pair(g - 1, b + 1)));
        if (r >= 1 && b >= 1) q.push(make_pair(r - 1, make_pair(g + 1, b - 1)));
        if (g >= 1 && b >= 1) q.push(make_pair(r + 1, make_pair(g - 1, b - 1)));
    }

    if (dp[0][0][1]) cout << "B";
    if (dp[0][1][0]) cout << "G";
    if (dp[1][0][0]) cout << "R";

    return 0;
}