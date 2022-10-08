#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

char a[21];
int n;
vector<int> num;

void Add(int k)
{
    if (k==0 || k==1) return;

    if (k==2 || k==3 || k==5 || k==7)
    {
        num.push_back(k);
    }
    else if (k==4)
    {
        num.push_back(3);
        num.push_back(2);
        num.push_back(2);
    }
    else if (k==6)
    {
        num.push_back(3);
        num.push_back(5);
    }
    else if (k==8)
    {
        num.push_back(7);
        num.push_back(2);
        num.push_back(2);
        num.push_back(2);
    }
    else if (k==9)
    {
        num.push_back(7);
        num.push_back(2);
        num.push_back(3);
        num.push_back(3);
    }
}

int main()
{
    int i;

    scanf("%d",&n);

    scanf("%s",a+1);

    for (i=1;i<=n;i++)
    {
        Add(a[i]-'0');
    }

    sort(num.begin(),num.end());

    for (i=(int)num.size()-1;i>=0;i--)
    {
        printf("%d",num[i]);
    }
    printf("\n");

    return 0;
}