#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,k;
pair<int,int> a[11000];

vector<int> choose;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    long long kk = 0;
    sort(a,a+n);
    reverse(a,a+n);
    for (int i = 0; i < k; i++) {
        choose.push_back(a[i].second);
        kk += a[i].first;
    }
    sort(all(choose));

    cout << kk << endl;

    choose[k-1] = n-1;

    int la = -1;
    for (int x : choose) {
        cout << x - la << " ";
        la = x;
    }

    return 0;
}