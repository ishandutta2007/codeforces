#include <bits/stdc++.h>
using namespace std;

pair<double, int> arr[1005];

int main() {
    int n, s, pop, x, y;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> pop;
        arr[i] = make_pair(sqrt((double)(x*x + y * y)), pop);
    }
    sort(arr, arr+n);
    for(int i = 0; i < n; i++) {
        s += arr[i].second;
        if(s >= 1000000) {
            printf("%.7f\n", arr[i].first);
            break;
        }
    }
    if(s < 1000000) {
        cout << -1 << endl;
    }
    return 0;
}