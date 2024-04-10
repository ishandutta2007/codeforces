#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a[24];

bool good() {
    bool ans = true;
    for (int i = 0; i < 6; ++i)
        ans &= (a[4 * i] == a[4 * i + 1] && a[4 * i + 1] == a[4 * i + 2] && a[4 * i + 2] == a[4 * i + 3]);
    return ans;
}

void rotate(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    int tmp = a[a1];
    a[a1] = a[a2];
    a[a2] = a[a3];
    a[a3] = a[a4];
    a[a4] = a[a5];
    a[a5] = a[a6];
    a[a6] = a[a7];
    a[a7] = a[a8];
    a[a8] = tmp;
}

void face(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
    if (good()) { cout << "YES" << endl; exit(0); }
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
    if (good()) { cout << "YES" << endl; exit(0); }
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
    rotate(a1, a2, a3, a4, a5, a6, a7, a8);
}

int main()
{
    ios_base::sync_with_stdio(false);

    for (int i = 0; i < 24; ++i)
        cin >> a[i];

    face(12, 13,  4,  5, 16, 17, 20, 21);
    face(14, 15,  6,  7, 18, 19, 22, 23);
    face( 0,  2,  4,  6,  8, 10, 23, 21);
    face( 1,  3,  5,  7,  9, 11, 22, 20);
    face(13, 15,  8,  9, 18, 16,  3,  2); // you retard, you forgot upper and lower faces!
    face(12, 14, 10, 11, 19, 17,  1,  0);

    cout << "NO" << endl;

    return 0;
}