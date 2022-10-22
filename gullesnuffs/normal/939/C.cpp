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

vector<int> a;

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    a.resize(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    int s, f;
    cin >> s >> f;
    int sum = 0;
    rep(i,0,f-s)
        sum += a[i];
    int t = s;
    int bestT = t;
    int bestSum = sum;
    rep(i,0,n) {
        sum += a[(i+f-s)%n];
        sum -= a[(i)%n];
        t--;
        if (t == 0)
            t = n;
        if (sum > bestSum || (sum == bestSum && t < bestT)) {
            bestSum = sum;
            bestT = t;
        }
    }
    cout << bestT << endl;
    cerr << bestSum << endl;
}