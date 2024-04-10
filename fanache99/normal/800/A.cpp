//#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 100000;
const double EPS = 1e-8;

int a[1 + MAXN], b[1 + MAXN];

bool Check(double period, int n, int p) {
    double need = 0;
    for (int i = 1; i <= n; i++)
        if (period * a[i] > b[i])
            need += (period * a[i] - b[i]) / p;
    if (need + EPS <= period)
        return true;
    return false;
}

int main() {
    int n, p;
    long long suma = 0, sumb = 0;
    cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }
    if (p >= suma) {
        cout << "-1\n";
        return 0;
    }
    double left = 0, right = 1.0 * sumb / (suma - p);
    for (int step = 1; step <= 70; step++) {
        double middle = (left + right) * 0.5;
        if (Check(middle, n, p))
            left = middle;
        else
            right = middle;
    }
    cout << fixed << setprecision(10) << left << "\n";
    return 0;
}