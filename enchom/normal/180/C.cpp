#include <iostream>
using namespace std;
struct letter
{
    int len;
    bool big;
};

letter Let[100001];
int L=0;

int main()
{
    string a;
    int i,j;
    bool currbig;
    int bigs=0,total=0;
    int mintotal=999999999;
    int smallssofar=0;
    int smalls=0;
    
    cin>>a;
    
    if (a[0]<='Z')
    currbig=true;
    else
    currbig=false;
    
    L++;
    Let[L].big=currbig;
    Let[L].len=1;
    
    for (i=1;i<a.length();i++)
    {
        if (currbig && a[i]<='Z')
        {
            Let[L].len++;
        }
        else if (currbig && a[i]>'Z')
        {
            L++;
            currbig=false;
            Let[L].big=currbig;
            Let[L].len=1;
        }
        else if (!currbig && a[i]<='Z')
        {
            currbig=true;
            L++;
            Let[L].big=currbig;
            Let[L].len=1;
        }
        else if (!currbig && a[i]>'Z')
        {
            Let[L].len++;
        }
    }
    for (i=1;i<=L;i++)
    {
        if (Let[i].big)
        bigs+=Let[i].len;
        else
        smalls+=Let[i].len;
    }
    mintotal=bigs;
    if (smalls<mintotal)
    mintotal=smalls;
    for (i=1;i<=L;i++)
    {
        if (Let[i].big)
        bigs-=Let[i].len;
        else
        {
            total=bigs+smallssofar;
            if (total<mintotal)
            mintotal=total;
            
            smallssofar+=Let[i].len;
        }
    }
    if (mintotal!=999999999)
    cout<<mintotal<<endl;
    else
    cout<<0<<endl;
    return 0;
}