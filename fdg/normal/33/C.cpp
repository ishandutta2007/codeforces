#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define ll long long

using namespace std;

int nums[100001]={0},pref[100001]={0},suf[100001]={0},mn[100001]={0},pos[100001]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    pref[0]=nums[0];
    for(int i=1;i<n;i++)
        pref[i]=pref[i-1]+nums[i];
    suf[n]=0;
    suf[n-1]=nums[n-1];
    for(int i=n-2;i>=0;i--)
        suf[i]=suf[i+1]+nums[i];
    mn[n]=0;
    pos[n]=n;
//  mn[n-1]=suf[n-1];
//  pos[n-1]=n-1;
    for(int i=n-1;i>=0;i--)
    {
        mn[i]=suf[i];
        pos[i]=i;
        if (mn[i]>mn[i+1])
        {
            mn[i]=mn[i+1];
            pos[i]=pos[i+1];
        }
    }
    int ans=-pref[n-1];
    if (ans<pref[n-1]) ans=pref[n-1];
    for(int i=0;i<n-1;i++)
    {
        int p=pos[i+1];
        int cur=-pref[i]-suf[p];
        int sum=0;
        if (i+1<=p-1)
        {
            sum=pref[p-1]-pref[i];
        }
        if (cur+sum>ans) ans=cur+sum;
    }
    for(int i=n-1;i>=0;i--)
    {
        int cur=-suf[i];
        if (i>0) cur+=pref[i-1];
        if (cur>ans) ans=cur;
    }
    printf("%d\n",ans);
    return 0;
}