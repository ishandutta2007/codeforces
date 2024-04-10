#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, k;

string board[2100];

int lefts[210000];
int rights[210000];
int ups[210000];
int downs[210000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'L') {
                if (j-i>=0) lefts[j - i]++;
            }
            else if (board[i][j] == 'R') {
                rights[j + i]++;
            }
            else if (board[i][j] == 'U') {
                if (i % 2 == 0) ups[j]++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cout << lefts[i] + rights[i] + ups[i] << " ";
    }
    cout << endl;

    return 0;
}