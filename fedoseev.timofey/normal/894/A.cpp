#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <map>
#include <bitset>
#include <random>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    long long cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                    ++cnt;
    cout << cnt << endl;
}