#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

struct cvor
{
    bool vr = 0;
    int kolko = 0;
    cvor *ld = 0, *dd = 0;
    cvor(bool _vr)
    {
        vr = _vr;
        kolko = 0;
        ld = 0;
        dd = 0;
    }
}root(0);

int q;
int x;
int rj;

cvor *novi;

void dodaj(cvor *tr, int dub)
{
    if(dub < 0) return;
    if(x & (1<<dub))
    {
        if(tr -> dd)
        {
            novi = tr -> dd;
        }
        else
        {
            novi = new cvor(1);
            tr -> dd = novi;
        }
        novi -> kolko++;
    }
    else
    {
        if(tr -> ld)
        {
            novi = tr -> ld;
        }
        else
        {
            novi = new cvor(0);
            tr -> ld = novi;
        }
        novi -> kolko++;
    }
    dodaj(novi, dub - 1);
    return;
}

void makni(cvor *tr, int dub)
{
    if(dub < 0) return;
    if(x & (1<<dub))
    {
        novi = tr -> dd;
        novi -> kolko--;
    }
    else
    {
        novi = tr -> ld;
        novi -> kolko--;
    }
    makni(novi, dub - 1);
    return;
}

void query(cvor *tr, int dub)
{
    if(dub < 0) return;
    if(x & (1<<dub))
    {
        if(tr -> ld && tr -> ld -> kolko)
        {
            rj |= (1<<dub);
            novi = tr -> ld;
        }
        else novi = tr -> dd;
    }
    else
    {
        if(tr -> dd && tr -> dd -> kolko)
        {
            rj |= (1<<dub);
            novi = tr -> dd;
        }
        else novi = tr -> ld;
    }
    query(novi, dub - 1);
    return;
}

int main()
{
    scanf("%d", &q);
    char c;
    x = 0;
    dodaj(&root, 30);
    REP(i, 0, q)
    {
        scanf("\n%c %d", &c, &x);
        if(c == '+')
        {
            dodaj(&root, 30);
        }
        else if(c == '-')
        {
            makni(&root, 30);
        }
        else
        {
            rj = 0;
            query(&root, 30);
            printf("%d\n", rj);
        }
    }
    return 0;
}