#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>



using namespace std;


#define M 1000000007


int m;
int cc[1000];
int C[1001][1001];


int c(int n, int k) {
    if (n < 2 * k) {
        k = n - k;
    }
    if (k == 0) {
        return 1;
    }
    if (k < 0) {
        return 0;
    }
    if (C[n][k] != 0) {
        return C[n][k];
    }
    C[n][k] = c(n - 1, k) + c(n - 1, k - 1);
    C[n][k] %= M;
    return C[n][k];
}


int main() {
    cin >> m;
    int omnom = 0;
    cin >> omnom;
    long long ans = 1;
    for (int i = 1; i < m; i++) {
        cin >> cc[i];
       // cout <<  c(omnom + cc[i] - 1, cc[i] - 1) << endl;
        ans = (ans * c(omnom + cc[i] - 1, cc[i] - 1)) % M;
        omnom += cc[i];
    }
    cout << ans << endl;
    return 0;
}