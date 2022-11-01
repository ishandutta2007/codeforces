#include <bits/stdc++.h>

using namespace std;

int N;
int x1, y1, x2, y2;

int main()
{
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    if(x1>x2)
        swap(x1, x2), swap(y1, y2);
    scanf("%d", &N);
    int a, b, c;
    int ans=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        bool b1=-1LL*x1*a-c<1LL*y1*b;
        bool b2=-1LL*x2*a-c<1LL*y2*b;
        ans+=(b1^b2);
    }
    printf("%d\n", ans);
    return 0;
}