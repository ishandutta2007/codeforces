#include <iostream>
#include <algorithm>
using namespace std;

typedef long long Int;

Int nums[2001];

int main()
{
    Int n;
    Int a,b;
    Int i;
    
    cin>>n;
    cin>>b>>a;
    for (i=1;i<=n;i++)
    {
        cin>>nums[i];
    }
    sort(nums+1,nums+1+n);
    if (nums[a]==nums[a+1])
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<nums[a+1]-nums[a]<<endl;
    }
    return 0;
}