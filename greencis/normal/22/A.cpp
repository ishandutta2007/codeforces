#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, x;
vector<int> v;

int main()
{
    cin >> n;
    while (n--) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    if (v.size() == 1) cout << "NO";
    else cout << v[1];

    return 0;
}