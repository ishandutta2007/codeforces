    
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;


int n, x;
int ans = 0;
int l[100000], r[100000];


int main() {
    cin >> n >> x;
    int s = 1;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        ans += r[i] - l[i] + 1;
        ans += l[i] - s - ((l[i] - s) / x) * x;
        s = r[i] + 1;
    }
    cout << ans << endl;
    return 0;
}