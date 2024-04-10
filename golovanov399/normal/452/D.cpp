#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{

    int k, n1, n2, n3, t1, t2, t3;
    cin >> k >> n1 >> n2 >> n3 >> t1 >> t2 >> t3;
    vector<int> a(k);
    for (int i = 0; i < k; i++){
        int time = 0;
        if (i >= n1) time = max(time, t1 + a[i - n1]);
        if (i >= n2) time = max(time, t2 + a[i - n2]);
        if (i >= n3) time = max(time, t3 + a[i - n3]);
        a[i] = time;
    }
    cout << t1 + t2 + t3 + a[k - 1] << "\n";

    return 0;
}