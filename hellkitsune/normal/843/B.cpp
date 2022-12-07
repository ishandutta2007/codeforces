#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

mt19937 mt(time(0));

int n, from, x;
int a[50000];

int myRand(int bound) {
    return mt() % bound;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> from >> x;
    forn(i, n) a[i] = i + 1;
    swap(a[0], a[from - 1]);
    random_shuffle(a + 1, a + n, myRand);
    int lastVal = -1;
    forn(i, min(1000, n)) {
        cout << "? " << a[i] << endl;
        int val, nx;
        cin >> val >> nx;
        if (val <= x && val > lastVal) {
            from = a[i];
            lastVal = val;
        }
    }
    lastVal = -1;
    while (from != -1) {
        cout << "? " << from << endl;
        int nx;
        cin >> lastVal >> nx;
        if (lastVal >= x) {
            break;
        }
        lastVal = -1;
        from = nx;
    }
    cout << "! " << lastVal << endl;
    return 0;
}