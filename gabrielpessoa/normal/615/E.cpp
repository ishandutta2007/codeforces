#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 1000;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E9+9;

int main() {
    ll l = 0, r = 1E9;
    ll n;
    cin >> n;
    while(r > l + 1) {
        ll m = (l+r)/2;
        ll ntemp = m*(m+1)*3;
        if(ntemp > n) {
            r = m;
        } else {
            l = m;
        }
    }
    ll volta = l;
    if(volta*(volta+1)*3 < n) {
        volta = r;
    }
    ll natual = volta*(volta+1)*3;
    ll x = volta*2;
    ll y = 0;
    //printf("%lld %lld\n", volta, natual);
    ll movesX[] = {-1, -2, -1, 1, 2, 1};
    ll movesY[] = {-2, 0, 2, 2, 0, -2};
    if(natual == n) {
        printf("%lld %lld\n", x, y);
        return 0;
    }
    for(int i = 0; i < 6; i++) {
        ll movesDone = min(volta, natual - n);
        natual -= movesDone;
        x += movesX[i] * movesDone;
        y += movesY[i] * movesDone;
        if(natual == n) {
            printf("%lld %lld\n", x, y);
            return 0;
        }
    }
    return 0;
}