// Codeforces Beta Round #6
// Problem C -- Alice, Bob and Chocolate
#include <cstdio>

#define maxN 100000

using namespace std;

int n, t[maxN], a, b, ta, tb;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i)
        scanf("%d", t + i);
    a = b = ta = tb;
    for(int i = 0; i < n; ++ i)
        if(ta <= tb)
            ta += t[a ++];
        else
            tb += t[n - (++ b)];
    printf("%d %d\n", a, b);
    return 0;
}