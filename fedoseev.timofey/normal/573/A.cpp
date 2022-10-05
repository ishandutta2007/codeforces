#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

bool check(int a) {
    while (a % 2 == 0) a /= 2;
    while (a % 3 == 0) a /= 3;
    return a == 1;
}

int main(){
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int gc = gcd(a[0], a[1]);
    for (int i = 2; i < n; ++i) gc = gcd(gc, a[i]);
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (!check(a[i] / gc)) flag = false;
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}