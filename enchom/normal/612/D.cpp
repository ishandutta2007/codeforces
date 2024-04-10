#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int n,k;

pair<int,int> segments[1000111];
int nums[2000111];
int L=0;

map<int,int> mymap;
map<int,int>::iterator myit;

int add[2000111];
int sub[2000111];

int ctr=0;

int realval[2000111];

vector< pair<int,int> > ans;

int main()
{
    int i;
    int a,b;
    int segm=0;
    int lastX=1;
    int cursum=0;
    bool dragging=false;
    int l;

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&segments[i].first,&segments[i].second);

        L++;
        nums[L]=segments[i].first;
        L++;
        nums[L]=segments[i].second;

        myit=mymap.find(a);
    }

    sort(nums+1,nums+1+L);

    for (i=1;i<=L;i++)
    {
        myit=mymap.find(nums[i]);

        if (myit==mymap.end())
        {
            ctr++;
            mymap.insert(make_pair(nums[i],ctr));

            realval[ctr]=nums[i];
        }
    }

    for (i=1;i<=n;i++)
    {
        myit=mymap.find(segments[i].first);
        a=(*myit).second;

        myit=mymap.find(segments[i].second);
        b=(*myit).second;

        add[a]++;
        sub[b]++;
    }

    for (i=1;i<=2000000;i++)
    {
        if (dragging)
        {
            cursum+=add[i];
            cursum-=sub[i];

            if (cursum<k)
            {
                ans.push_back(make_pair(realval[l],realval[i]));

                dragging=false;
            }
        }
        else
        {
            cursum+=add[i];

            if (cursum>=k)
            {
                dragging=true;
                l=i;
            }

            cursum-=sub[i];

            if (cursum<k && dragging)
            {
                dragging=false;

                ans.push_back(make_pair(realval[l],realval[i]));
            }
        }
    }

    printf("%d\n",(int)ans.size());

    for (i=0;i<ans.size();i++)
    {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }

    return 0;
}