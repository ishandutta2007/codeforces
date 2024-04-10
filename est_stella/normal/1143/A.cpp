#include<bits/stdc++.h>
using namespace std;

int arr[200001];

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int i=n-1; i>0; i--)
    {
        if(arr[i]!=arr[i+1])
        {
            printf("%d", i);
            return 0;
        }
    }
}