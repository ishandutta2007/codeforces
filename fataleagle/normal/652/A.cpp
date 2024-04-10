#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long h1, h2, a, b;
    cin>>h1>>h2>>a>>b;
    int day=0;
    int hour=14;
    for(int i=0; i<5000000; i++)
    {
        if(hour==10)
            day++;
        if(hour>=10 && hour<22)
            h1+=a;
        else
            h1-=b;
        if(h1>=h2)
            return printf("%d\n", day), 0;
        hour++;
        if(hour==24)
            hour=0;
    }
    printf("-1\n");
    return 0;
}