#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int h1, m1, h2, m2, h3, m3;

int main() {
    scanf("%2d:%2d", &h1, &m1);
    scanf("%2d:%2d", &h2, &m2);

    m3 = (h2 - h1) * 60 + m2 - m1;
    m3 /= 2;

    h3 = h1 + m3 / 60;
    if(m1 + m3 % 60 >= 60) h3++;

    printf("%02d:%02d\n", h3, (m1 + m3 % 60) % 60);
    return 0;
}