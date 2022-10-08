#include <iostream>
#include <algorithm>
using namespace std;

struct num
{
    int val,orgind;
};

num a[100001];
int n;

bool SortEm(num a,num b)
{
    return (a.val<b.val);
}

int main()
{
    int i;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].orgind=i;
    }
    
    
    sort(a+1,a+n+1,SortEm);
    if (n==1)
    {
        cout<<a[1].orgind<<endl;
    }
    else
    {
        if (a[1].val==a[2].val)
        cout<<"Still Rozdil"<<endl;
        else
        cout<<a[1].orgind<<endl;
    }
    return 0;
}