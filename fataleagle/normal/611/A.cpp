#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    string S;
    cin>>N;
    cin>>S;
    cin>>S;
    if(S=="week")
    {
        N--;
        int d=4;
        int ans=0;
        for(int i=0; i<366; i++)
        {
            if(d==N)
                ans++;
            d=(d+1)%7;
        }
        printf("%d\n", ans);
    }
    else
    {
        if(N<=29)
            printf("12\n");
        else if(N==30)
            printf("11\n");
        else
            printf("7\n");
    }
    return 0;
}