#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector < vector <char> > a;
int n, m;

bool check(int x, int y) {
    for (int j = 0; j < m; j++)
        if (a[x][j] != a[y][j])
            return false;
    return true;
}

void exitNo() {
    cout << "No" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    a.resize(n, vector <char> (m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector <bool> used(n, false);
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true;
        for (int k = i + 1; k < n; k++)
            for (int j = 0; j < m; j++)
                if ((a[i][j] == '#') && (a[k][j] == '#')) {
                    if (!check(i, k)) exitNo();
                    used[k] = true; break;
                }
    }
    cout << "Yes" << endl;
    return 0;
}