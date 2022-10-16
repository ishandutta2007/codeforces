#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

int v[1 + MAXN];

bool checkLower(int n, int x) {
    for (int i = 1; i <= n; i++) {
        if (v[i] > x + i - 1) {
            return false;
        }
    }
    return true;
}

bool checkUpper(int n, int x, int p) {
    int t = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && v[j] <= x + i - 1) {
            j++;
            t++;
        }
        if (t >= p) {
            return false;
        }
        t--;
    }
    return true;
}

int main(){
    //ifstream cin("input.txt");
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    int left = v[1], right = v[n], from = v[n];
    while (left <= right) {
        int middle = (left + right) / 2;
        if (checkLower(n, middle)) {
            from = middle;
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    left = v[1], right = v[n];
    int to = v[1] - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (checkUpper(n, middle, p)) {
            to = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    cout << max(0, to - from + 1) << "\n";
    for (int i = from; i <= to; i++) {
        cout << i << " ";
    }
    return 0;
}