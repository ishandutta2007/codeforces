#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int c1=0;
    int start=0, last=0;

    for(int i=1; i<=n; i++)
    {
        int c;
        scanf("%d", &c);

        if(i==1) c1=c;
        if(c1!=c && start==0) start = i;
        if(c1!=c) last=i;

        if(i==n)
        {
            if(c!=c1) printf("%d", n-1);
            else printf("%d", last-1 > n-start ? last-1 : n-start);
        }
    }
}