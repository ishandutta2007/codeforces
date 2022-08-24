#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(all(a));
    int d = 0;
    for (int i = 0; i < n - 1; i++){
        d = max(a[i + 1] - a[i], d);
    }
    d = max(d, 2 * a[0]);
    d = max(d, 2 * (l - a.back()));
    if (d & 1){
        cout << d / 2 << ".5" << "\n";
    } else {
        cout << d / 2 << "\n";
    }

    return 0;
}