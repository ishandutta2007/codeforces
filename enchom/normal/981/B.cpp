#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
typedef long long llong;

map<int,int> mymap;
map<int,int>::iterator myit;
int n;
int a,b;

int main()
{
    int i,j;
    llong ans = 0;

    for (i=1;i<=2;i++)
    {
        scanf("%d",&n);

        for (j=1;j<=n;j++)
        {
            scanf("%d %d",&a,&b);

            myit = mymap.find(a);

            if (myit == mymap.end())
            {
                mymap.insert(make_pair(a,b));
            }
            else
            {
                if ( (*myit).second < b )
                {
                    mymap.erase(myit);
                    mymap.insert(make_pair(a,b));
                }
            }
        }
    }

    for (myit=mymap.begin();myit!=mymap.end();myit++)
    {
        ans += (llong)( (*myit).second );
    }

    printf("%lld\n",ans);

    return 0;
}