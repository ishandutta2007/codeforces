#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;
    printf("%d\n", (a+2*b+c+2*d+e+2*f)*(a+2*b+c+2*d+e+2*f)/9-b*b-d*d-f*f);
    return 0;
}