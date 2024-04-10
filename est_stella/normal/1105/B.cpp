#include<stdio.h>

int n, k;
char a[200010];
int num[100];

int main()
{
    scanf("%d %d", &n, &k);

    scanf("%s", a);

    char c=a[0];
    int l=0;

    for(int i=0; i<n; i++)
    {
        if(a[i]==c)
        {
            l++;
            if(l==k)
            {
                num[c-'a']++;
                l=0;
            }
        }
        else
        {
            c=a[i];
            l=1;
            if(l==k)
            {
                num[c-'a']++;
                l=0;
            }
        }
    }

    int Max=0;

    for(int i=0; i<52; i++)
    {
        if(Max < num[i]) Max=num[i];
    }

    printf("%d", Max);
}