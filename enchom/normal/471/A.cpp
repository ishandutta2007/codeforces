#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int arr[10];
vector<int> nums;

int main()
{
    int i,j;
    int a;
    bool legs=false;

    for (i=1;i<=6;i++)
    {
        scanf("%d",&a);
        arr[a]++;
    }

    for (i=1;i<=9;i++)
    {
        if (arr[i]>=4)
        {
            legs=true;
            arr[i]-=4;
            break;
        }
    }

    if (!legs)
    {
        printf("Alien\n");
        return 0;
    }

    for (i=1;i<=9;i++)
    {
        for (j=1;j<=arr[i];j++)
        {
            nums.push_back(i);
        }
    }

    if (nums[0]==nums[1])
    printf("Elephant\n");
    else
    printf("Bear\n");

    return 0;
}