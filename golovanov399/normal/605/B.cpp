#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int main(){

    int n = nxt(), m = nxt();
    vector<pair<pair<int, int>, int>> a(m);
    for (int i = 0; i < m; i++){
        a[i].first.first = nxt();
        a[i].first.second = 1 - nxt();
        a[i].second = i;
    }
    sort(all(a));

    int cur = 1, cnt = 0;
    for (int i = 0; i < m; i++){
        if (a[i].first.second == 0){
            cnt += cur - 1;
            cur += 1;
        } else {
            if (cnt > 0)
                cnt--;
            else {
                puts("-1");
                return 0;
            }
        }
    }

    vector<pair<int, int>> ans(m);
    cur = 0;
    int x = 1, y = 3;
    for (int i = 0; i < m; i++){
        if (a[i].first.second == 0){
            ans[a[i].second] = {cur + 1, cur + 2};
            cur++;
        } else {
            ans[a[i].second] = {x, y};
            x += 1;
            if (x == y - 1){
                y++;
                x = 1;
            }
        }
    }

    for (auto x : ans)
        printf("%d %d\n", x.first, x.second);

    return 0;
}