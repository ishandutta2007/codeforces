#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <array>
#include <list>
typedef long long ll;
using namespace std;

int solve(vector<int>& a, vector<int>& b)
{
    int n = a.size(), m = b.size(), sum = 0;
    vector<int> good(n, 0);
    set<int> s(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        if (s.count(a[i]))
        {
            good[i] = 1;
            sum++;
        }
    }
    int ans = sum;
    int push = 0, in = 0;
    for (int i = 0; i < m; i++)
    {
        while (push < n && a[push] <= b[i] + push)
        {
            sum -= good[push];
            push++;
        }
        int boxes = upper_bound(b.begin(), b.end(), b[i] + push - 1) - b.begin() - i;
        ans = max(boxes + sum, ans);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a1, a2, b1, b2;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a < 0) a1.push_back(-a);
            else a2.push_back(a);
        }
        for (int i = 0; i < m; i++)
        {
            int b;
            cin >> b;
            if (b < 0) b1.push_back(-b);
            else b2.push_back(b);
        }
        reverse(a1.begin(), a1.end());
        reverse(b1.begin(), b1.end());
        //cout << "                       ";
        cout << solve(a1, b1) + solve(a2, b2) << "\n";
    }
    return 0;
}