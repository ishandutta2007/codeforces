#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, v; cin >> n >> v;
    vector < pair<int,int> > a, b;
    for (int i = 0; i < n; i++)
    {
        int k, g; cin >> k >> g;
        if (k == 1) a.push_back({g, i});
            else b.push_back({g, i});
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector <int> pa, pb;
    pa.push_back(0);
    for (int i = 0; i < a.size(); i++) pa.push_back(*pa.rbegin() + a[i].first);
    pb.push_back(0);
    for (int i = 0; i < b.size(); i++) pb.push_back(*pb.rbegin() + b[i].first);
    int bestI, bestJ, bestVal = 0;
    for (int i = 0; i < pa.size(); i++)
    {
        if (v < i) continue;
        int curVal = 0, vLeft = (v - i) / 2;
        if (vLeft >= pb.size()) vLeft = pb.size() - 1;
        int cnt = pa[i] + pb[vLeft];
        if (cnt >= bestVal)
        {
            bestVal = cnt;
            bestI = i;
            bestJ = vLeft;
        }
    }
    cout << bestVal << endl;
    for (int i = 0; i < bestI; i++) cout << a[i].second + 1 << endl;
    for (int j = 0; j < bestJ; j++) cout << b[j].second + 1 << endl;
}