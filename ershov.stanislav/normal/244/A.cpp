#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, k, *used;
    cin >> n >> k;
    vector<int> res;
    used = new int[n*k];
    for (int i=0; i<n*k; i++) used[i] = false;
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        res.push_back(a);
        used[a-1] = true;
    }
    int m=0;
    for (int i=0; i<k; i++) {
        cout << endl << res[i] << ' ';
        for (int j=1; j<n; j++) {
            while(used[m]) m++;
            cout << m+1 << ' ';
            m++;
        }
    }
    return 0;
}