#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, d, e, f;

int main()
{
    cin>>n>>a>>b>>c>>d>>e>>f;
    n-=a;
    n-=c;
    n-=e;
    b-=a;
    d-=c;
    f-=e;
    for(int i=b; i>=0; i--) if(a<=i+a && i+a<=a+b && 0<=n-i && n-i<=d+f)
    {
        for(int j=d; j>=0; j--) if(c<=j+c && j+c<=c+d && e<=e+n-i-j && e+n-i-j<=e+f)
        {
            printf("%d %d %d\n", a+i, c+j, e+n-i-j);
            break;
        }
        break;
    }
    return 0;
}