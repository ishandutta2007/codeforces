# include <iostream>
# include <vector>

using namespace std;

const int MAXN = 100005;
int remainder[MAXN];
vector <vector <int>> num(MAXN);

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++remainder[x % m];
        num[x % m].push_back(x);
    }
    for (int i = 0; i < m; ++i) {
        if (remainder[i] >= k) {
            cout << "Yes" << endl;
            for (int j = 0; j < k; ++j) cout << num[i][j] << " ";
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}