//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//#include <queue>
//#include <stack>

#define REP0(a, b)  for(int a = 0; a < (b); ++a)
#define REP1(a, b)  for(int a = 1; a < (b); ++a)
#define ALL(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<int> c (k, 0);

    REP0(i,n) {
        int in;
        cin >> in;
        in--;
        c[in]++;
    }

    int count = 0;
    int ns = 0;

    REP0(i,k) {
        if (c[i] % 2 == 0)
            count += c[i];
        else {
            count += c[i] - 1;
            ns += 1;
        }
    }

    count += ns/2;

    if (n % 2 == 1)
        count++;

    cout << count << endl;

    return 0;
}