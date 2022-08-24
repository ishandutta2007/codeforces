#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<int> a;

int f(int l, int r){
    if (r == l) return 1; else
    if (r < l) return 0; else {
        int m = 1000000009;
        for (int i = l; i <= r; i++) m = min(m, a[i]);
        for (int i = l; i <= r; i++) a[i] -= m;
        int s = m;
        int i = l - 1;
        for (int j = l; j <= r; j++){
            if (a[j] == 0){
                s += f(i + 1, j - 1);
                i = j;
            }
        }
        s += f(i + 1, r);
        return min(s, r - l + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << f(0, n - 1) << "\n";

    return 0;
}