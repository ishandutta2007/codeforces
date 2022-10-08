#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int a,b,c;
int n;
int t[200111];

multiset<int> HC;
multiset<int>::iterator myit;

vector<int> HitA;
vector<int> HitB;
vector<int> HitC;

vector<int> HitAB;
vector<int> HitBC;
vector<int> HitAC;

void S()
{
    int d;

    if (a>b)
    {
        d=a;
        a=b;
        b=d;
    }

    if (b>c)
    {
        d=b;
        b=c;
        c=d;
    }

    if (a>b)
    {
        d=a;
        a=b;
        b=d;
    }

    return;
}

void Rem(int p)
{
    myit=HC.upper_bound(p);
    myit--;

    HC.erase(myit);

    return;
}

int main()
{
    int i;
    int ans=0;
    bool doubleshot;

    scanf("%d",&n);

    scanf("%d %d %d",&a,&b,&c);

    S();

    for (i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);

        if (t[i]<=a)
        {
            HitA.push_back(t[i]);
        }
        else if (t[i]<=b)
        {
            HitB.push_back(t[i]);
        }
        else if (t[i]<=c)
        {
            HitC.push_back(t[i]);
        }
        else
        {
            if (t[i]>a+b && t[i]>a+c && t[i]>b+c)
            {
                if (t[i]<=a+b+c)
                ans++; ///triple
                else
                {
                    printf("-1\n");
                    return 0;
                }
            }
            else
            {
                if (t[i]<=a+b)
                {
                    HitAB.push_back(t[i]);
                }
                else if (t[i]<=a+c)
                {
                    HitAC.push_back(t[i]);
                }
                else
                {
                    HitBC.push_back(t[i]);
                }
            }
        }
    }

    sort(HitA.begin(),HitA.end());
    sort(HitB.begin(),HitB.end());
    sort(HitC.begin(),HitC.end());

    for (i=0;i<HitAB.size();i++)
    {
        ans++;

        if (!HitC.empty())
        {
            HitC.pop_back();
        }
        else if (!HitB.empty())
        {
            HitB.pop_back();
        }
        else if (!HitA.empty())
        {
            HitA.pop_back();
        }
    }

    for (i=0;i<HitAC.size();i++)
    {
        ans++;

        if (!HitB.empty())
        {
            HitB.pop_back();
        }
        else if (!HitA.empty())
        {
            HitA.pop_back();
        }
    }

    for (i=0;i<HitBC.size();i++)
    {
        ans++;

        if (!HitA.empty())
        {
            HitA.pop_back();
        }
    }

    for (i=0;i<HitC.size();i++)
    {
        HC.insert(HitC[i]);
    }

    ///

    while(!HitA.empty() || !HitB.empty() || !HC.empty())
    {
        ///C attack

        ans++;

        if (!HC.empty())
        {
            Rem(c);
        }
        else if (!HitB.empty())
        HitB.pop_back();
        else if (!HitA.empty())
        HitA.pop_back();

        ///A+B attack on C

        doubleshot=false;

        if (HitA.empty() || (HitB.empty() && HitA.size()==1))
        {
            if (!HC.empty())
            {
                if ( (a+b)>=(*HC.begin()) )
                {
                    Rem(a+b);
                    doubleshot=true;
                }
            }
        }

        if (!doubleshot)
        {
            ///B shot
            if (!HitB.empty())
            HitB.pop_back();
            else if (!HitA.empty())
            HitA.pop_back();

            ///A shot
            if (!HitA.empty())
            HitA.pop_back();
        }
    }

    printf("%d\n",ans);

    return 0;
}