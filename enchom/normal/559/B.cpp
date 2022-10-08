#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char arr[200111];
char a[200111];
char b[200111];
int n;

char s1[200111];
int L1=0;
char s2[200111];
int L2=0;

bool Normal()
{
    int i;

    for (i=1;i<=L1;i++)
    {
        if (s1[i]<s2[i])
        return true;
        else if (s1[i]>s2[i])
        return false;
    }

    return true;
}

void MergeSort(int L,int R)
{
    int i;
    int mid;

    if ( (L+R)%2==0 ) ///odd length
    return;

    mid=(L+R)/2;

    MergeSort(L,mid);
    MergeSort(mid+1,R);

    L1=0;
    L2=0;
    for (i=L;i<=mid;i++)
    {
        L1++;
        s1[L1]=arr[i];
    }

    for (i=mid+1;i<=R;i++)
    {
        L2++;
        s2[L2]=arr[i];
    }

    if (Normal())
    {
        for (i=L;i<=mid;i++)
        {
            arr[i]=s1[i-L+1];
        }

        for (i=mid+1;i<=R;i++)
        {
            arr[i]=s2[i-(mid+1)+1];
        }
    }
    else
    {
        for (i=L;i<=mid;i++)
        {
            arr[i]=s2[i-L+1];
        }

        for (i=mid+1;i<=R;i++)
        {
            arr[i]=s1[i-(mid+1)+1];
        }
    }

    return;
}

int main()
{
    int i;

    scanf("%s",a+1);
    n=strlen(a+1);

    for (i=1;i<=n;i++)
    {
        arr[i]=a[i];
    }

    MergeSort(1,n);

    for (i=1;i<=n;i++)
    {
        a[i]=arr[i];
    }

    scanf("%s",b+1);

    for (i=1;i<=n;i++)
    {
        arr[i]=b[i];
    }

    MergeSort(1,n);

    for (i=1;i<=n;i++)
    {
        b[i]=arr[i];
    }

    for (i=1;i<=n;i++)
    {
        if (a[i]!=b[i])
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");

    return 0;
}