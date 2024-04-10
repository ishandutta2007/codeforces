#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
typedef long long ll;
using namespace std;

const int N = 501;
class pairvr
{
public:
    int u, v;
};
vector<int>k(N);
bool cmp(pairvr& a, pairvr& b) { return abs(k[a.u] - k[a.v]) > abs(k[b.u] - k[b.v]); }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> k[i];
    vector<pairvr> qu;
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
    {
        pairvr p; p.u = i, p.v = j;
        if (k[p.u] < k[p.v]) swap(p.u, p.v); // k[p.u] >= k[p.v]
        qu.push_back(p);
    }
    sort(qu.begin(), qu.end(), cmp);
    for (int i = 0; i < qu.size(); i++)
    {
        cout << "? " << qu[i].u + 1 << " " << qu[i].v + 1 << endl; 
        string ans;
        cin >> ans;
        if (ans == "Yes")
        {
            cout  << "! " << qu[i].u + 1 << " " << qu[i].v + 1 << endl;
            return 0;
        }
    }
    cout << "! 0 0" << endl;
    return 0;
}