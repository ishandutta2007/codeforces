#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>
#include <map>

#define ll long long

using namespace std;

int nums[100005];
map <int,int> l,g;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    sort(nums,nums+n);
    int w,cnt=0;
    for(int i=0;i<n-1;i++)
    {
        if (nums[i]==nums[i+1])
        {
            w=nums[i];
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        if (nums[i]<w) l[nums[i]]++;
        else if (nums[i]==w) cnt++;
        else g[nums[i]]++;
    }
    bool ok=true;
    int tot=0;
    if (nums[n-1]>w)
    {
        for(int i=w+1;i<nums[n-1];i++)
        {
            if (g[i]<2)
            {
                ok=false;
                break;
            }
            else g[i]-=2;
        }
        g[nums[n-1]]--;
        tot++;
        map <int,int>::iterator it=g.end(); it--;
        for(map <int,int>::iterator it1;it!=g.begin();it--)
        {
            if (it->second>0)
            {
                it1=it; it1--;
                if (it1->second<it->second)
                {
                    ok=false;
                    break;
                }
                it1->second-=it->second;
            }
        }
        tot+=g[w+1]; g[w+1]=0;
    }
    if (nums[0]<w)
    {
        for(int i=w-1;i>nums[0];i--)
        {
            if (l[i]<2)
            {
                ok=false;
                break;
            }
            else l[i]-=2;
        }
        l[nums[0]]--;
        tot++;
        for(map <int,int>::iterator it=l.begin(),it1;it!=l.end();it++)
        {
            if (it->second>0)
            {
                it1=it; it1++;
                if (it1==l.end()) break;
                if (it1->second<it->second)
                {
                    ok=false;
                    break;
                }
                it1->second-=it->second;
            }
        }
        tot+=l[w-1]; l[w-1]=0;
    }
    if (ok&&tot<cnt||(n&1)) ok=false;
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}