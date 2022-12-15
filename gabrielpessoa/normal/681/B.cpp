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

const int SIZE = 1005;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;


int main() {
    ll n;
    cin >> n;
    while(n >= 0) {
        for(ll b = 0; b <= n/123456; b++) {
            if((n - b * 123456) % 1234 == 0) {
                puts("YES");
                return 0;
            }
        }
        n -= 1234567;
    }
    puts("NO");
    return 0;
}