#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int>f(26, 0);
    for (int i = 0; i < n; i++) f[s[i] - 'a']++;
    if (n == 1 || *max_element(f.begin(), f.end()) > 1)
       cout << "Yes\n";
    else cout << "No\n";
    return 0;
}