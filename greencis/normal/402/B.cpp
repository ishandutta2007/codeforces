#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int n,k,a[1005];
int mn=2e9,mni=-1,mnqq;

int main()
{

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] - i*k <= 0) continue;
        int mnq = a[i] - i*k;
        int q = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] != mnq + j*k) ++q;
        }
        if (q < mn) {
            mn = q;
            mni = i;
            mnqq = mnq;
        }
    }

    cout << mn << endl;
    for (int i = 0; i < n; ++i) {
        if (a[i] > mnqq + i*k) {
            cout << "- " << i+1 << " " << abs(a[i] - (mnqq + i*k)) << endl;
        } else if (a[i] <  mnqq + i*k) {
            cout << "+ " << i+1 << " " << abs(a[i] - (mnqq + i*k))<< endl;
        }
    }

    return 0;
}