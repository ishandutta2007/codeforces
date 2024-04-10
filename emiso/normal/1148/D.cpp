#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, a[MN], b[MN], iv[MN];
vector<pair<int, int>> sob, des;

bool cmpsob(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

bool cmpdes(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &a[i], &b[i]);
        iv[a[i]] = i + 1;
        if(a[i] < b[i]) sob.emplace_back(a[i], b[i]);
        else des.emplace_back(a[i], b[i]);
    }

    if(sob.size() > des.size()) {
        sort(sob.begin(), sob.end(), cmpsob);
        printf("%d\n", sob.size());
        for(auto tt : sob) printf("%d ", iv[tt.first]);
    } else {
        sort(des.begin(), des.end(), cmpdes);
        printf("%d\n", des.size());
        for(auto tt : des) printf("%d ", iv[tt.first]);
    }

    return 0;
}