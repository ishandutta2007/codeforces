#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pp;

bool compare(const pp a, const pp b) {return (a.first==b.first)?a.second>b.second:a.first<b.first; }

int main()
{
    ll n, a, b, c, d, x, y; char g;
    cin >> n >> b >> g >> a >> d >> g >> c;
    vector<pp> v;
    for (int i=0; i<n; i++) {
        cin >> x >> y;
        pp p(x*d-y*c, y*a-x*b);
        if (p.first>0&&p.second>0) v.push_back(p);
    }
    sort(v.begin(), v.end(), compare);
    set<ll> s;
    for (int i=0; i<v.size(); i++) if (s.insert(v[i].second).second) {
        set<ll>::iterator in = s.find(v[i].second);
        if (++in != s.end()) s.erase(in);
    }
    cout << s.size();
    return 0;
}