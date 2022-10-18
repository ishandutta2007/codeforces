#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int u[100000];
vector<int> a, b;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    for (int i = 2; i * i <= sum; ++i) {
        if (sum % i == 0) {
            int cur = i;
            for (int j = n; cur > 0 && j >= 1; --j) {
                if (j > cur || u[j]) continue;
                u[j] = 1;
                a.push_back(j);
                cur -= j;
            }
            sort(all(a));
            for (int j = 1; j <= n; ++j)
                if (!u[j])
                    b.push_back(j);
            cout << "Yes\n";
            cout << a.size(); for (int x : a) cout << " " << x; cout << endl;
            cout << b.size(); for (int x : b) cout << " " << x; cout << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}