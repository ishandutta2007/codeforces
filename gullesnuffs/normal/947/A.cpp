#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int smallestIn[1000005];
bool isPrime[1000005];

int largestFactor(int n) {
    for (int i = 2; i*i <= n; i++) {
        while (n%i == 0) {
            n /= i;
            if (n == 1)
                return i;
        }
    }
    return n;
}

int main(){
	ios::sync_with_stdio(0);
    isPrime[1] = 0;
    for (int p = 2; p <= 1000000; p++) {
        isPrime[p] = 1;
    }
    for (int p = 2; p <= 1000000; p++) {
        if (!isPrime[p])
            continue;
        for (int i = 2*p; i <= 1000000; i++) {
            isPrime[i] = 0;
        }
    }
    int x;
    cin >> x;
    int s = largestFactor(x);
    int ans = x;
    for (int i = x-s+1; i < x; i++) {
        int t = largestFactor(i);
        if (t < i) {
            ans = min(ans, i-t+1);
        }
        else
            ans = min(ans, t);
    }
    cout << ans << endl;
}