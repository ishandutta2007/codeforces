#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        int n;
        scanf("%d", &n);
        printf("%s\n", n % 4 ? "NO" : "YES");
    }
    return 0;
}