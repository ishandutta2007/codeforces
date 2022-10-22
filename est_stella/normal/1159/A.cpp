#include<bits/stdc++.h>
using namespace std;

int n, cnt, Min;

int main()
{
    scanf("%d", &n);
    scanf("\n");

    for(int i=0; i<n; i++)
    {
        char x;
        scanf("%c", &x);

        if(x=='+') cnt++;
        else cnt--;

        Min = min(cnt, Min);
    }

    printf("%d", cnt-Min);
}