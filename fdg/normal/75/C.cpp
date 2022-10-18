#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

#define ll long long

using namespace std;

set <int> f,f1;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    int F=sqrt(a+0.)+1;
    for(int i=1;i<=F;i++)
    {
        if (a%i==0)
        {
            f1.insert(i);
            f1.insert(a/i);
        }
    }
    F=sqrt(b+0.)+1;
    for(int i=1;i<=F;i++)
    {
        if (b%i==0)
        {
            if (f1.count(i)) f.insert(i);
            if (f1.count(b/i)) f.insert(b/i);
        }
    }
    int low,high;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&low,&high);
        set <int>::iterator it=f.upper_bound(high);
        it--;
        if ((*it)>=low&&(*it)<=high) printf("%d\n",*it);
        else printf("-1\n");
    }
    return 0;
}