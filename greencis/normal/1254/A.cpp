#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string alphabet;

char s[105][105], t[105][105];
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);

    for (int i = '0'; i <= '9'; ++i) alphabet.push_back(i);
    for (int i = 'A'; i <= 'Z'; ++i) alphabet.push_back(i);
    for (int i = 'a'; i <= 'z'; ++i) alphabet.push_back(i);
    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n, m, k;
        cin >> n >> m >> k;
        int rice = 0;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
            for (int j = 0; j < m; ++j) {
                rice += s[i][j] == 'R';
                t[i][j] = 0;
            }
        }
        int idx_chicken = 0;
        int cur_rice = 0;
        int x = 0, y = 0, dir = 0;
        while (idx_chicken < k) {
            t[y][x] = alphabet[idx_chicken];
            if (s[y][x] == 'R') ++cur_rice;
            if (cur_rice * k >= (idx_chicken + 1) * rice) ++idx_chicken;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || t[ny][nx]) {
                ++dir %= 4;
                nx = x + dx[dir];
                ny = y + dy[dir];
            }
            x = nx;
            y = ny;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (t[i][j] == 0) t[i][j] = alphabet[k-1];
            }
            t[i]    [m] = 0;
            cout << t[i] << endl;
        }
    }
}