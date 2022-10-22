#include<bits/stdc++.h>
using namespace std;

long long a, b, c;

int main()
{
    scanf("%lld %lld %lld", &a, &b, &c);

    printf("%lld", 2*c + min(a, b)*2 + (a!=b));
}