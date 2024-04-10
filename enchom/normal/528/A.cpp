#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
typedef long long Int;

set<int> H;
set<int> V;
set<int>::iterator myit;

multiset<int> Hdif;
multiset<int> Vdif;
multiset<int>::iterator it;

int w,h,n;
char ch[3];

void AddV(int x)
{
    int val;
    set<int>::iterator it1,it2;

    myit=V.insert(x).first;
    it1=myit;
    it2=myit;

    it1--;
    it2++;

    val=(*it2)-(*it1);
    Vdif.erase( Vdif.find(val) );

    Vdif.insert( (*it2)-(*myit) );
    Vdif.insert( (*myit)-(*it1) );

    return;
}

void AddH(int x)
{
    int val;
    set<int>::iterator it1,it2;

    myit=H.insert(x).first;
    it1=myit;
    it2=myit;

    it1--;
    it2++;

    val=(*it2)-(*it1);
    Hdif.erase( Hdif.find(val) );

    Hdif.insert( (*it2)-(*myit) );
    Hdif.insert( (*myit)-(*it1) );

    return;
}

int main()
{
    int i;
    int x;
    int V1,V2;

    scanf("%d %d %d",&w,&h,&n);

    H.insert(0);
    H.insert(h);

    V.insert(0);
    V.insert(w);

    Hdif.insert(h);
    Vdif.insert(w);

    for (i=1;i<=n;i++)
    {
        scanf("%s",ch);

        scanf("%d",&x);

        if (ch[0]=='V')
        {
            AddV(x);
        }
        else
        {
            AddH(x);
        }

        it=Vdif.end();
        it--;
        V1=(*it);

        it=Hdif.end();
        it--;
        V2=(*it);

        printf("%lld\n",(Int)V1*(Int)V2);
    }

    return 0;
}