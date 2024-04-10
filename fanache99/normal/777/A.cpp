//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int Try(int x, int n) {
    int v[3] = {0, 0, 0};
    v[x] = 1;
    for (int i = 1; i <= n; i++)
        if (i % 2)
            swap(v[0], v[1]);
        else
            swap(v[1], v[2]);
    for (int i = 0; i <= 2; i++)
        if (v[i])
            return i;
}

int main() {
    int n, x;
    cin >> n >> x;
    n %= 6;
    if (Try(0, n) == x) {
        cout << "0\n";
        return 0;
    }
    if (Try(1, n) == x) {
        cout << "1\n";
        return 0;
    }
    if (Try(2, n) == x) {
        cout << "2\n";
        return 0;
    }
    return 0;
}