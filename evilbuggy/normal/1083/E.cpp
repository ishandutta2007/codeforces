#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct Rectangle{
    ll a, x, y;
};

bool cmp(Rectangle &a, Rectangle &b){
    return a.x < b.x;
}

deque<pair<ll, ll> > hull;

ll compute(int ind, ll y){
    return y*hull[ind].first + hull[ind].second;
}

ll binarySearch(ll y){
    while(hull.size() > 1 && compute(0, y) < compute(1, y))hull.pop_front();
    return compute(0, y);
}

ll dp[1000005];
Rectangle rect[1000005];
int n;

bool func(ll m1, ll c1, ll m2, ll c2, ll m3, ll c3){
    if(c2 <= c3){
        if(c1 >= c2)return true;
        ll a1 = (c3-c2)/(m3-m2);
        ll b1 = (c2-c1)/(m2-m1);
        ll a2 = (c3-c2)%(m3-m2);
        ll b2 = (c2-c1)%(m2-m1);
        if(a1 != b1)return a1 > b1;
        return a2*(m2-m1) >= b2*(m3-m2);
    }else{
        if(c1 <= c2)return false;
        ll a1 = (c2-c3)/(m3-m2);
        ll b1 = (c1-c2)/(m2-m1);
        ll a2 = (c2-c3)%(m3-m2);
        ll b2 = (c1-c2)%(m2-m1);
        if(a1 != b1)return a1 < b1;
        return a2*(m2-m1) <= b2*(m3-m2);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>rect[i].x>>rect[i].y>>rect[i].a;
    }
    sort(rect + 1, rect + n + 1, cmp);

    hull.push_back(make_pair(0, 0));
    ll x, y, a;
    ll ans = dp[1];
    for(int i = 1; i <= n; i++){
        x = rect[i].x, y = rect[i].y, a = rect[i].a;
        dp[i] = -a + x*y + binarySearch(-y);
        int sz;
        while((sz = hull.size()) > 1){
            if(func(hull[sz-2].first, hull[sz-2].second, hull[sz-1].first, hull[sz-1].second, x, dp[i])){
                hull.pop_back();
            }else{
                break;
            }
        }
        hull.push_back(make_pair(x, dp[i]));
        ans = max(ans, dp[i]);
    }
    cout<<ans<<endl;
}