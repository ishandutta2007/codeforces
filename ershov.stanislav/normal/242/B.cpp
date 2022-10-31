#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, left=2000000000, right=0, l2, r2, res = 0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        l2 = left;
        r2 = right;
        if (a < left) left = a;
        if (b > right) right = b;
        if (left == a && right == b) res = i + 1;
        else if (left != l2 || right != r2) res = -1;
    }
    cout << res;
}