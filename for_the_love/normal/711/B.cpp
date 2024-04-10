#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;

long long a[N][N];

int n;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        cin >> a[i][j];
    if (n == 1) {
        puts("1");
        return 0;
    }

    int found = 0;
    long long sum = 0;
    for (int i = 0; i < n && !found; i++) {
        int flag = 0;
        long long temp = 0;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) flag = 1;
            temp += a[i][j];
        }
        if (!flag) found = 1, sum = temp;
    }

    for (int i = 0; i < n && !found; i++) {
        int flag = 0;
        long long temp = 0;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 0) flag = 1;
            temp += a[j][i];
        }
        if (!flag) found = 1, sum = temp;
    }

    if (!found) {
        int flag = 0;
        long long temp = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][i] == 0) flag = 1;
            temp += a[i][i];
        }
        if (!flag) found = 1, sum = temp;
    }

    if (!found) {
        int flag = 0;
        long long temp = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][n - i - 1] == 0) flag = 1;
            temp += a[i][n - i - 1];
        }
        if (!flag) found = 1, sum = temp;
    }

    int x, y;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    if (a[i][j] == 0){
        x = i, y = j;
    }

    long long temp = 0;
    for (int i = 0; i < n; i++) {
        temp += a[x][i];
    }

    a[x][y] = sum - temp;
    if (a[x][y] <= 0) {
        puts("-1");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        long long temp = 0;
        for (int j = 0; j < n; j++)
            temp += a[i][j];
        if (temp != sum) {
            puts("-1");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        long long temp = 0;
        for (int j = 0; j < n; j++)
            temp += a[j][i];
        if (temp != sum) {
            puts("-1");
            return 0;
        }
    }
    temp = 0;
    for (int i = 0; i < n; i++)
        temp += a[i][i];
    if (temp != sum) {
        puts("-1");
        return 0;
    }
    temp = 0;
    for (int i = 0; i < n; i++)
        temp += a[i][n - i - 1];
    if (temp != sum) {
        puts("-1");
        return 0;
    }

    cout << a[x][y] << endl;
}