#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

int a[100001];
int n;
pair<int,int> nums[100001];
int L=0;
Int F[100001];

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    //freopen("sample.txt","r",stdin);

    int i;
    Int add;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a+1,a+1+n);

    L=1;
    nums[1]=make_pair(a[1],1);

    for (i=2;i<=n;i++)
    {
        if (a[i]==a[i-1])
        {
            nums[L].second++;
        }
        else
        {
            L++;
            nums[L]=make_pair(a[i],1);
        }
    }

    F[0]=0;
    F[1]=(Int)nums[1].first*(Int)nums[1].second;

    //cout<<"F[1]="<<F[1]<<endl;

    for (i=2;i<=L;i++)
    {
        //cout<<"Computing F["<<i<<"]"<<endl;
        ///If we take this one
        add=(Int)nums[i].first*(Int)nums[i].second;
        //cout<<"Addition is "<<add<<endl;

        if (nums[i-1].first<nums[i].first-1)
        {
            //cout<<"No collission"<<endl;
            F[i]=add+F[i-1];
        }
        else
        {
            //cout<<"Collission"<<endl;
            F[i]=add+F[i-2];
        }

        ///If we don't take this one
        F[i]=MAX(F[i],F[i-1]);
    }

    printf("%I64d\n",F[L]);

    return 0;
}