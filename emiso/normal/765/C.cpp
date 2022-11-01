#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int k, a, b;

int main() {
    scanf("%d %d %d", &k, &a, &b);
    int flag = 1, rema, remb, ans = 0;

    rema = a % k;
    remb = b % k;
    ans = (a / k) + (b / k);

    if(rema > 0 && (b / k) == 0) flag = 0;
    if(remb > 0 && (a / k) == 0) flag = 0;


    printf("%d\n", flag ? ans : -1);

    return 0;
}