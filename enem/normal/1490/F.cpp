#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<int> v(n), w;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]^123456]++;
        }

        for(auto i : m) w.push_back(i.second);

        sort(w.begin(), w.end());

        int removal = n, len = w.size();
        for(int i = 0; i < len; i++)
        {
            int keep = (len - i) * w[i];
            removal = min(removal, n - keep);
        }

        cout << removal << '\n';
    }

    return 0;
}