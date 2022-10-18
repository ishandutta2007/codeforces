#include <bits/stdc++.h>
using namespace std;

struct place {
    int x, y, add;
    bool operator<(const place& rhs) const {
        return add < rhs.add;
    }
};

int n, k;
string s[105];

int main() {
    cin >> n >> k;
    vector<place> places;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < 12; ++j)
            if (s[i][j] == '.')
                places.push_back((place){j, i, (j > 0 && s[i][j - 1] == 'S') + (j < 11 && s[i][j + 1] == 'S')});
    }
    sort(places.begin(), places.end());
    for (int i = 0; i < k; ++i)
        s[places[i].y][places[i].x] = 'x';
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 12; ++j)
            if (s[i][j] == 'S')
                ans += (j > 0 && (s[i][j - 1] == 'P' || s[i][j - 1] == 'x' || s[i][j - 1] == 'S')) + (j < 11 && (s[i][j + 1] == 'P' || s[i][j + 1] == 'x' || s[i][j + 1] == 'S'));
    cout << ans << "\n";
    for (int i = 0; i < n; ++i)
        cout << s[i] << "\n";
}