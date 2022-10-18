#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        v.push_back(1);
        while (v.size() > 1 && v[v.size() - 2] == v[v.size() - 1]) {
            int x = v.back();
            v.pop_back();
            v.pop_back();
            v.push_back(x + 1);
        }
    }
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    return 0;
}