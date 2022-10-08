#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char str[100001];

Int ctr[32][13][4];

bool CorrectDay(Int days,Int month)
{
    if (days>31 || days<1)
    return false;
    if (month<1 || month>12)
    return false;
    
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
    {
        if (days>31)
        return false;
    }
    if (month==4 || month==6 || month==9 || month==11)
    {
        if (days>30)
        return false;
    }
    if (month==2)
    {
        if (days>28)
        return false;
    }
    
    return true;
}

bool Digit(char ch)
{
    if (ch>='0' && ch<='9')
    return true;
    else
    return false;
}

Int Dig(char ch)
{
    return (Int)ch-(Int)'0';
}

int main()
{
    Int L;
    Int i,j,in;
    Int month,day;
    Int maxcur=0;
    
    for (i=0;i<=31;i++)
    {
        for (j=0;j<=12;j++)
        {
            for (in=0;in<=3;in++)
            {
                ctr[i][j][in]=0;
            }
        }
    }
    
    scanf("%s",str);
    
    L=strlen(str);
    
    for (i=6;i<L-3;i++)
    {
        if (str[i]=='2' && str[i+1]=='0' && str[i+2]=='1' && str[i+3]=='3')
        {
            if (str[i-1]=='-')
            {
                if ( Digit(str[i-2]) && Digit(str[i-3]) )
                {
                    month=Dig(str[i-3])*10+Dig(str[i-2]);
                    if ( str[i-4]=='-' )
                    {
                        if ( Digit(str[i-5]) && Digit(str[i-6]) )
                        {
                            day=Dig(str[i-6])*10+Dig(str[i-5]);
                            if (CorrectDay(day,month))
                            {
                                ctr[day][month][1]++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (i=6;i<L-3;i++)
    {
        if (str[i]=='2' && str[i+1]=='0' && str[i+2]=='1' && str[i+3]=='4')
        {
            if (str[i-1]=='-')
            {
                if ( Digit(str[i-2]) && Digit(str[i-3]) )
                {
                    month=Dig(str[i-3])*10+Dig(str[i-2]);
                    if ( str[i-4]=='-' )
                    {
                        if ( Digit(str[i-5]) && Digit(str[i-6]) )
                        {
                            day=Dig(str[i-6])*10+Dig(str[i-5]);
                            if (CorrectDay(day,month))
                            {
                                ctr[day][month][2]++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (i=6;i<L-3;i++)
    {
        if (str[i]=='2' && str[i+1]=='0' && str[i+2]=='1' && str[i+3]=='5')
        {
            if (str[i-1]=='-')
            {
                if ( Digit(str[i-2]) && Digit(str[i-3]) )
                {
                    month=Dig(str[i-3])*10+Dig(str[i-2]);
                    if ( str[i-4]=='-' )
                    {
                        if ( Digit(str[i-5]) && Digit(str[i-6]) )
                        {
                            day=Dig(str[i-6])*10+Dig(str[i-5]);
                            if (CorrectDay(day,month))
                            {
                                ctr[day][month][3]++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for (i=1;i<=31;i++)
    {
        for (j=1;j<=12;j++)
        {
            for (in=1;in<=3;in++)
            {
                if (ctr[i][j][in]>maxcur)
                maxcur=ctr[i][j][in];
            }
        }
    }
    for (i=1;i<=31;i++)
    {
        for (j=1;j<=12;j++)
        {
            for (in=1;in<=3;in++)
            {
                if (ctr[i][j][in]==maxcur)
                {
                    if (i<10)
                    {
                        printf("0%I64d-",i);
                    }
                    else
                    {
                        printf("%I64d-",i);
                    }
                    if (j<10)
                    {
                        printf("0%I64d-",j);
                    }
                    else
                    {
                        printf("%I64d-",j);
                    }
                    printf("%I64d\n",2012+in);
                    return 0;
                }
            }
        }
    }
}