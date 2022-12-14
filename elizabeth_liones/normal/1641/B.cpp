#include <algorithm>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <random>
typedef long long ll;
using namespace std;

void perform(vector<int> a, vector<pair<int, int> > p)
{
    for (pair<int, int> i : p)
    {
        a.insert(a.begin() + i.first, i.second);
        a.insert(a.begin() + i.first, i.second);
    }
    cout << a.size() << "\n";
    for (int i : a) cout << i << " ";
    cout << "\n\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        //vector<int> a2 = a;
        vector<pair<int, int> > ans;
        vector<int> l;
        int len = 0; // length of already erased tandem repeats
        while (a.size())
        {
            int i = 1;
            while (i < a.size() && a[i] != a[0]) i++;
            if (i == a.size()) break;
            l.push_back(i * 2);
            for (int j = 1; j < i; j++)
            {
                ans.push_back({ len + i + j, a[j] });
            }
            reverse(a.begin() + 1, a.begin() + i);
            a.erase(a.begin() + i);
            a.erase(a.begin());
            len += i * 2;
        }
        if (a.size())
        {
            cout << "-1\n";
        }
        else
        {
            //perform(a2, ans);
            cout << ans.size() << "\n";
            for (pair<int, int> i : ans) cout << i.first << " " << i.second << "\n";
            cout << l.size() << "\n";
            for (int i : l) cout << i << " ";
            cout << "\n";
        }
        //cout << "\n\n\n";
    }
    return 0;
}