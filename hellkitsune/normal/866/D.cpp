#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
priority_queue<int, vector<int>, greater<int> > q, sold;

int main() {
    scanf("%d", &n);
    LL ans = 0;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        int bestQ = (q.empty() ? INF : q.top());
        int bestSold = (sold.empty() ? INF : sold.top());
        if (bestQ < min(x, bestSold)) {
            q.pop();
            ans += x - bestQ;
            sold.push(x);
        } else if (bestSold < x) {
            sold.pop();
            q.push(bestSold);
            ans += x - bestSold;
            sold.push(x);
        } else {
            q.push(x);
        }
    }
    cout << ans << endl;
    return 0;
}