#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x % 4 == 1) printf("0 A\n");
    else if (x % 4 == 2) printf("1 B\n");
    else if (x % 4 == 3) printf("2 A\n");
    else printf("1 A\n");
    return 0;
}