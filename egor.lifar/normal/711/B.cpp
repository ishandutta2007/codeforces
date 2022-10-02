#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string.h>
#include <stdio.h>
#include <algorithm>


using namespace std;


int n;
long long a[500][500];


int main() {
    cin >> n;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 0) {
                pos = i;
            }
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int pos1 = (pos != 0 ? 0: 1);
    long long sum = 0;
    for (int j = 0; j < n; j++) {
        sum += a[pos1][j];
    }
    long long sum1 = 0;
    int pos2 = -1;
    for (int j = 0; j < n; j++) {
        if (a[pos][j] == 0) {
            pos2 = j;
        }
        sum1 += a[pos][j];
    }
    if (sum <= sum1) {
        cout << -1 << endl;
        return 0; 
    }
    a[pos][pos2] = sum - sum1;
    for (int i = 0; i < n; i++) {
        long long sum2 = 0;
        for (int j = 0; j < n; j++) {
            sum2 += a[i][j];
        }
        if (sum2 != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        long long sum2 = 0;
        for (int j = 0; j < n; j++) {
            sum2 += a[j][i];
        }
        if (sum2 != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    long long sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += a[i][i];
    }
    if (sum2 != sum) {
        cout << -1 << endl;
        return 0;
    }
    sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += a[i][n - i - 1];
    }
    if (sum2 != sum) {
        cout << -1 << endl;
        return 0;
    }
    cout << a[pos][pos2] << endl;
    return 0;
}