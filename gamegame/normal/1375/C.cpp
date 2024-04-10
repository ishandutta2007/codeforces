
#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    while(N--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        int pos1;
        int posn;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1)
                pos1=i;
            else if(a[i]==n)
                posn=i;
        }
        if(a[0]<a[n-1])
            printf("YES\n");
        else
            printf("NO\n");
    }
}