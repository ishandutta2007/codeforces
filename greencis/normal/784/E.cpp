#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int a, b, c, d;
int A, B, C, D;
int x, y;
int z;

int main()
{
    cin >> a >> b >> c >> d;
    A = a ^ b;
    B = c | d;
    C = b & c;
    D = a ^ d;
    x = A & B;
    y = C | D;
    z = x ^ y;
    cout << z << endl;

    return 0;
}

/*
0000 +
0010 +
0100 +
0111 +
1111 +
*/