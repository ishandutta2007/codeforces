#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

bool compare(int a, int b) {return a>b; }

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i=0; i<n; i++) cin >> c[i];
    sort(c.begin(), c.end(), compare);
    int a=0, b=0, d=0;
    while (a < k) {
        cout << b+1 << ' ';
        for (int i=0; i<b; i++) cout << c[i] << ' ';
        cout << c[d] << ' ';
        cout << endl;
        if (++d >= n) {
            b++;
            d=b;
        }
        a++;
    }
    return 0;
}