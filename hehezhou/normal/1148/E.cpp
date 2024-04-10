#include <bits/stdc++.h>
#define mp make_tuple
using namespace std;
typedef tuple<int, int, int> node;
vector< tuple<int, int, int> > ans;
int t[300010], n;
pair<int, int> s[300010];
multiset<node> set1, set2;
int main() {
    long long sum1 = 0, sum2 = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &s[i].first);
        s[i].second = i;
        sum1 += s[i].first;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", t + i);
        sum2 += t[i];
    }
    sort(t + 1, t + 1 + n);
    sort(s + 1, s + 1 + n);
    if(sum1 != sum2) return puts("NO"), 0;
    for(int i = 1; i <= n; i++) {
        if(s[i].first == t[i]) continue;
        if(s[i].first < t[i]) set1.insert(mp(t[i], t[i] - s[i].first, s[i].second));
        else set2.insert(mp(t[i], s[i].first - t[i], s[i].second));
    }
    while(1) {
        if(set1.empty() && set2.empty()) break; 
        if(set1.empty() || set2.empty()) return puts("NO"), 0;
        auto x = *set1.begin(), y = *set2.begin();
        if(get<0>(x) > get<0>(y)) return puts("NO"), 0;
        set1.erase(x), set2.erase(y);
        if(get<1>(x) == get<1>(y)) ans.push_back(mp(get<2>(x), get<2>(y), get<1>(x)));
        else if(get<1>(x) < get<1>(y)) ans.push_back(mp(get<2>(x), get<2>(y), get<1>(x))), set2.insert(mp(get<0>(y), get<1>(y) - get<1>(x), get<2>(y)));
        else ans.push_back(mp(get<2>(x), get<2>(y), get<1>(y))), set1.insert(mp(get<0>(x), get<1>(x) - get<1>(y), get<2>(x)));
    }
    printf("YES\n%d\n", ans.size());
    for(auto i : ans) printf("%d %d %d\n", get<0>(i), get<1>(i), get<2>(i));
    return 0;
}