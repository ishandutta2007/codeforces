#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct log
{
    char timelog[21];///filled to 19
    Int seconds;
};

log logs[1000001];
Int date[13][32];

void GetMonths()
{
    Int month=1,day=1;
    Int days=0;
    
    while(month<13)
    {
        date[month][day]=days;
        days++;
        day++;
        if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
        {
            if (day==32)
            {
                day=1;
                month++;
            }
        }
        else if ( month==4 || month==6 || month==9 || month==11 )
        {
            if (day==31)
            {
                day=1;
                month++;
            }
        }
        else
        {
            if (day==30)
            {
                day=1;
                month++;
            }
        }
    }
}

Int GETINT(char ch)
{
    return (Int)( (Int)ch-(Int)'0' );
}

bool SortLogs(log a,log b)
{
    return (a.seconds<b.seconds);
}

int main()
{
    Int i,j,n,m;
    char ch;
    bool timelogged=true;
    Int ctr=0;
    Int logctr=0;
    Int month,day;
    Int hour,minute,second;
    Int backto;
    
    scanf("%I64d %I64d",&n,&m);
    scanf("%c",&ch);
    
    while(1)
    {
        timelogged=true;
        logctr++;
        
        if (logctr!=1)
        {
            ctr=1;
            logs[logctr].timelog[ctr]=ch;
        }
        else
        {
            ctr=0;
        }
        
        while(scanf("%c",&ch)==1)
        {
            if (timelogged)
            {
                ctr++;
                logs[logctr].timelog[ctr]=ch;
            }
            if (ctr==19 && timelogged)
            {
                timelogged=false;
            }
            if (ch==10)
            break;
        }
        if (scanf("%c",&ch)!=1)
        break;
    }
    
    GetMonths();
    
    for (i=1;i<=logctr;i++)
    {
        month=GETINT(logs[i].timelog[6])*10+GETINT(logs[i].timelog[7]);
        day=GETINT(logs[i].timelog[9])*10+GETINT(logs[i].timelog[10]);
        hour=GETINT(logs[i].timelog[12])*10+GETINT(logs[i].timelog[13]);///12 13
        minute=GETINT(logs[i].timelog[15])*10+GETINT(logs[i].timelog[16]);///15 16
        second=GETINT(logs[i].timelog[18])*10+GETINT(logs[i].timelog[19]);///18 19
        
        logs[i].seconds=date[month][day]*86400+hour*3600+minute*60+second;
    }
    sort(logs+1,logs+1+logctr,SortLogs);
    for (i=1;i<=logctr;i++)
    {
        backto=i-m+1;
        if (backto>=1)
        {
            if ( logs[i].seconds-logs[backto].seconds+1<=n )
            {
                for (j=1;j<=19;j++)
                {
                    printf("%c",logs[i].timelog[j]);
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("-1\n");
}