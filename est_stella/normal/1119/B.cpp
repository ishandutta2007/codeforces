#include<bits/stdc++.h>
using namespace std;

int arr[1001];
priority_queue <int> pQ;
int ans=0, n, h;

int main()
{
    scanf("%d%d", &n, &h);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<=n; i++)
    {
        int sum=0;

        while(!pQ.empty()) pQ.pop();

        for(int j=1; j<=i; j++)
            pQ.push(arr[j]);

        for(int j=1; j<=i; j++)
        {
            if(j&1) sum+=pQ.top();
            pQ.pop();
        }

        if(sum>h) break;
        ans=i;
    }

    printf("%d", ans);
}