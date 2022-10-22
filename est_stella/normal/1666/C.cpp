#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0);
#define fi first
#define se second
#define em emplace
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int x[3];
int y[3];

int main() {
    fast;

    for(int i=0; i<3; i++) cin >> x[i] >> y[i];

    int X = x[0] + x[1] + x[2] - min({x[0], x[1], x[2]}) - max({x[0], x[1], x[2]});
    int Y = y[0] + y[1] + y[2] - min({y[0], y[1], y[2]}) - max({y[0], y[1], y[2]});

    int cnt = 0;
    for(int i=0; i<3; i++) {
        if(mp(x[i], y[i]) != mp(x[i], Y)) cnt++;
        if(mp(x[i], Y) != mp(X, Y)) cnt++;
    }
    
    cout << cnt << "\n";

    for(int i=0; i<3; i++) {
        if(mp(x[i], y[i]) != mp(x[i], Y)) cout << x[i] << " " << y[i] << " " << x[i] << " " << Y << "\n";
        if(mp(x[i], Y) != mp(X, Y)) cout << x[i] << " " << Y << " " << X << " " << Y << "\n";
    }
}