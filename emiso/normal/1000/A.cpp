#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

map<string, int> freq;
string str;
ll n, ans;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> str;
        freq[str]++;
    }

    for(int i = 0; i < n; i++) {
        cin >> str;
        freq[str]--;
    }

    for(auto a : freq) {
        ans += abs(a.second);
    }

    assert(ans % 2 == 0);
    printf("%lld\n", ans / 2);
    return 0;
}