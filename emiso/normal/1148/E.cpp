#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, s[MN], t[MN], id[MN];
pair<int, int> orig[MN];
priority_queue<pair<int, int>> pq;

struct ch {
    int i, j, d;
};
vector<ch> ans;

void cant() { puts("NO"); exit(0);}

int main() {
    scanf("%lld", &n);

    for(int i = 0; i < n; i++) {
        scanf("%lld", &s[i]);
        orig[i] = {s[i], i};
    } sort(orig, orig + n);

    for(int i = 0; i < n; i++) {
        s[i] = orig[i].first;
        id[i] = orig[i].second;
    }

    for(int i = 0; i < n; i++) {
        scanf("%lld", &t[i]);
    } sort(t, t + n);

    for(int i = 0; i < n; i++) {
       if(s[i] < t[i]) pq.push({s[i], i});
       else if(s[i] > t[i]) {
            while(s[i] > t[i]) {
                if(pq.empty()) cant();
                int j = pq.top().second; pq.pop();

                int d1 = t[j] - s[j], d2 = s[i] - t[i];
                if(d1 <= d2) {
                    ans.push_back({id[j], id[i], d1});
                    s[i] -= d1;
                } else {
                    ans.push_back({id[j], id[i], d2});
                    s[j] += d2;
                    s[i] -= d2;
                    pq.push({s[j], j});
                }
            }
       }
    }

    if(!pq.empty()) cant();

    printf("YES\n%d\n", ans.size());
    for(auto tt : ans) {printf("%d %d %d\n", tt.i+1, tt.j+1, tt.d);}
    return 0;
}