#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stack>
#pragma GCC optimize("O3")
using namespace std;

char a[10];
stack<long long> s;

int main(void)
{
    int n, x;
    long long o;

    scanf("%d", &n);
    s.push(1);
    for(o = 0; n --; )
    {
        scanf("%s", a);
        if(a[0] == 'a')
        {
            o += s.top();
            if(o >= 4294967296LL)
            {
                puts("OVERFLOW!!!");
                return 0;
            }
        }
        else if(a[0] == 'f')
        {
            scanf("%d", &x);
            s.push(min(s.top() * x, 4294967296LL));
        }
        else
            s.pop();
    }
    printf("%I64d\n", o);

    return 0;
}