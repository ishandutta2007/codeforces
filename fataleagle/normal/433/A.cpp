#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin>>n;
    int na=0, nb=0;
    for(int i=0; i<n; i++)
    {
        cin>>k;
        if(k==100)
            na++;
        else
            nb++;
    }
    bool dp[2001]={0};
    dp[0]=true;
    for(int t=0; t<na; t++)
        for(int i=2000; i>=10; i--)
            if(dp[i-10])
                dp[i]=true;
    for(int t=0; t<nb; t++)
        for(int i=2000; i>=20; i--)
            if(dp[i-20])
                dp[i]=true;
    if(dp[(na*10+nb*20)/2])
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}