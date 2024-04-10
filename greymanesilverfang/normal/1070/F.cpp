#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 400005;

int n, x, ans = 0, cnt, cnta, cntb, cntc, a[N], b[N], c[N], people = 0;
string s;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> x;
        if (s == "11")
        {
            ans += x;
            cnt++;
        }
        else if (s == "01") b[++cntb] = x;
        else if (s == "10") a[++cnta] = x;
        else c[++cntc] = x;
    }
    sort(b + 1, b + 1 + cntb, cmp);
    sort(a + 1, a + 1 + cnta, cmp);
    sort(c + 1, c + 1 + cntc, cmp);
    for (int i = 1; i <= min(cntb, cnta); i++) ans += b[i] + a[i];
    people = cnt + 2 * min(cntb, cnta);
    cnt += min(cntb, cnta);
    int j = 1, add = 0;
    if (cntb > cnta)
    {
        int i = cnta + 1;
        while (add + people < 2 * cnt && i <= cntb && j <= cntc)
        {
            if (b[i] > c[j])
            {
                ans += b[i];
                i++;
            }
            else
            {
                ans += c[j];
                j++;
            }
            add++;
        }
        while (add + people < 2 * cnt && i <= cntb)
        {
            ans += b[i];
            i++;
            add++;
        }
    }
    else if (cntb < cnta)
    {
        int i = cntb + 1;
        while (add + people < 2 * cnt && i <= cnta && j <= cntc)
        {
            if (a[i] > c[j])
            {
                ans += a[i];
                i++;
            }
            else
            {
                ans += c[j];
                j++;
            }
            add++;
        }
        while (add + people < 2 * cnt && i <= cnta)
        {
            ans += a[i];
            i++;
            add++;
        }
    }
    while (add + people < 2 * cnt && j <= cntc)
    {
        ans += c[j];
        j++;
        add++;
    }
    cout << ans;
	return 0;
}