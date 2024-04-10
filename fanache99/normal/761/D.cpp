//#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const int INF = 2000000010;

int a[1 + MAXN], b[1 + MAXN];
pair<int, int> c[1 + MAXN];

int main() {
    int n, low, high;
    cin >> n >> low >> high;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c + 1, c + n + 1);
    int before = -INF;
    for (int i = 1; i <= n; i++) {
        int j = c[i].second;
        if (high - a[j] <= before) {
            cout << "-1\n";
            return 0;
        }
        if (low - a[j] > before)
            b[j] = low;
        else
            b[j] = before + 1 + a[j];
        before = b[j] - a[j];
    }
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
    return 0;
}