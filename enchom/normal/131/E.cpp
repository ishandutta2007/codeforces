#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long Int;

struct lolz
{
    Int first,last;
};
struct cell
{
    Int row,col;
};

lolz rows[100001];
lolz columns[100001];
lolz secdiagonal[200001];
lolz firstdiagonal[200011];
cell queens[100001];
Int OFFSET=100003;
Int t[9];

int main()
{
    Int n,m;
    Int i;
    Int a,b;
    Int x,y;
    Int currt=0;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=0;i<=8;i++)
    {
        t[i]=0;
    }
    for (i=0;i<=100000;i++)
    {
        rows[i].first=999999999;
        rows[i].last=-1;
        
        columns[i].first=999999999;
        columns[i].last=-1;
    }
    for (i=0;i<=200010;i++)
    {
        firstdiagonal[i].first=999999999;
        firstdiagonal[i].last=-1;
        
        secdiagonal[i].first=999999999;
        secdiagonal[i].last=-1;
    }
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        
        if (rows[a].first>b)
        rows[a].first=b;
        if (rows[a].last<b)
        rows[a].last=b;
        
        if (columns[b].first>a)
        columns[b].first=a;
        if (columns[b].last<a)
        columns[b].last=a;
        
        if (secdiagonal[a+b].first>b)
        secdiagonal[a+b].first=b;
        if (secdiagonal[a+b].last<b)
        secdiagonal[a+b].last=b;
        
        if (firstdiagonal[a-b+OFFSET].first>b)
        firstdiagonal[a-b+OFFSET].first=b;
        
        if (firstdiagonal[a-b+OFFSET].last<b)
        firstdiagonal[a-b+OFFSET].last=b;
        
        queens[i].row=a;
        queens[i].col=b;
    }
    //cout<<firstdiagonal[100001].first<<" "<<firstdiagonal[100001].last<<endl;
    for (i=1;i<=m;i++)
    {
        currt=0;
        x=queens[i].row;
        y=queens[i].col;
        
        //cout<<x<<" "<<y<<endl;
        
        if (rows[x].first!=y)
        {
            //cout<<1<<endl;
            currt++;
        }
        if (rows[x].last!=y)
        {
            //cout<<2<<endl;
            currt++;
        }
        if (columns[y].first!=x)
        {
            //cout<<3<<endl;
            currt++;
        }
        if (columns[y].last!=x)
        {
            //cout<<4<<endl;
            currt++;
        }
        if (secdiagonal[x+y].first!=y)
        {
            //cout<<5<<endl;
            currt++;
        }
        if (secdiagonal[x+y].last!=y)
        {
            //cout<<6<<endl;
            currt++;
        }
        if (firstdiagonal[x-y+OFFSET].first!=y)
        {
            //cout<<7<<endl;
            currt++;
        }
        if (firstdiagonal[x-y+OFFSET].last!=y)
        {
            //cout<<8<<endl;
            currt++;
        }
        t[currt]++;
    }
    for (i=0;i<=8;i++)
    {
        printf("%I64d",t[i]);
        if (i==8)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}