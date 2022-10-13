#include <bits/stdc++.h>
using namespace std;

int cnt[100100][3];

string check(int cnt[], int len)
{
    if (len < 3) return "YES";
    sort(cnt, cnt + 3, greater <int>());
    for (int i = 0; i < 3; i++)
        if (cnt[i] != len / 3 + (i < len % 3))
            return "NO";
    return "YES";
}

int main()
{
    string s;
    cin >> s;
    
    int n = s.size(), m, l, r;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cnt[i + 1][j] = cnt[i][j] + (s[i] - 'x' == j);
    
    cin >> m;
    while (m--)
    {
        cin >> l >> r;
        int curCnt[3];
        for (int i = 0; i < 3; i++) curCnt[i] = cnt[r][i] - cnt[l - 1][i];
        cout << check(curCnt, r - l + 1) << endl;
    }
}