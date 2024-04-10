#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

char p[1001005];
int n,ans[1001005];
int curidx;
int lastidx;

int main()
{
    scanf("%s",p);
    n = strlen(p);
    if (p[0] != '(' || p[n-1] == '(') { printf("-1"); return 0; }
    for (int i = n-1; i >= 0; --i) {
        if (p[i] == '#') {
            lastidx = i;
            break;
        }
    }

    int balance = 0;
    int oldbalance = 0;
    for (int i = 0; i <= n-1; ++i) {
        if (p[i] == '(') {
            ++balance;
        } else if (p[i] == ')') {
            --balance;
            if (balance < 0) { printf("-1"); return 0; }
        } else if (p[i] == '#') {
            ans[curidx++] = 1;
            --balance;
            if (lastidx == i) oldbalance = balance;
            if (balance < 0) { printf("-1"); return 0; }
        }
    }
    if (balance > oldbalance) { printf("-1"); return 0; }
    ans[curidx-1] += balance;
    for (int i = 0; i < curidx; ++i)
        printf("%d\n",ans[i]);

    return 0;
}