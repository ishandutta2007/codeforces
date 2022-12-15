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

const int SIZE = 1E5+5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E9+9;

ll capacity[SIZE];
int main() {
    ll n, vtotal = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        ll vatual;
        cin >> vatual;
        vtotal += vatual;
    }
    for(int i = 0; i < n; i++) {
        cin >> capacity[i];
    }
    sort(capacity, capacity+n);
    if(vtotal <= capacity[n-1] + capacity[n-2]) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}