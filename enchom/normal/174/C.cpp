#include <iostream>
using namespace std;
struct rangeincrease
{
    int l,r;
};

rangeincrease actions[100001];
rangeincrease inprogress[100001];
int actionL=0;
int nums[100001];
int opened=0;

int main()
{
    int n;
    int i;
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    {
        cin>>nums[i];
    }
    for (i=1;i<=n;i++)
    {
        while (nums[i]>opened)
        {
            opened++;
            inprogress[opened].l=i;
        }
        while (nums[i]<opened)
        {
            inprogress[opened].r=i-1;
            actionL++;
            actions[actionL].l=inprogress[opened].l;
            actions[actionL].r=inprogress[opened].r;
            opened--;
        }
    }
    while (opened>0)
    {
        inprogress[opened].r=n;
        actionL++;
        actions[actionL].l=inprogress[opened].l;
        actions[actionL].r=inprogress[opened].r;
        opened--;
    }
    cout<<actionL<<endl;
    for (i=1;i<=actionL;i++)
    {
        cout<<actions[i].l<<" "<<actions[i].r<<endl;
    }
    return 0;
}