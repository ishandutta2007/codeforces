#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct r
{
    Int tn,ac;
};

r mem[10][1000001];

Int F[1000001];

void Wait()
{
    char ch;
    cin>>ch;
    return;
}

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

r solve(Int prenum,Int num)
{
    ///Wait();
    ///cout<<prenum<<" "<<num<<endl;
    if (num==0)
    {
        r ret;
        ret.ac=0;
        ret.tn=0;
        return ret;
    }
    if (num<10)
    {
        r ret;
        if (prenum<=num)
        {
            ret.ac=1;
            ret.tn=0;
            return ret;
        }
        else
        {
            ret.ac=0;
            ret.tn=num;
            return ret;
        }
    }
    if (num<=1000000)
    {
        if (mem[prenum][num].ac!=-1)
        {
            return mem[prenum][num];
        }
    }

    Int fd;
    Int num2;
    Int wd;
    Int powerof10;
    r ans;
    Int actions=0;
    r ret;
    Int onum=num;
    Int len=0;
    Int i;

    while(1)
    {
        powerof10=1;
        fd=num;
        num2=0;
        wd=0;
        len=0;

        while(fd>9)
        {
            num2=num2*10+(fd%10);
            len++;
            fd/=10;
            powerof10*=10;
        }

        for (i=1;i<=len;i++)
        {
            wd=wd*10+(num2%10);
            num2/=10;
        }

        ///cout<<"decomposed to "<<fd<<" and "<<wd<<endl;

        ans=solve(MAX(prenum,fd),wd);

        num=fd*powerof10+ans.tn;
        ///cout<<"getting our result we have "<<num<<endl;
        actions+=ans.ac;

        num-=MAX(prenum,fd);
        ///cout<<"so cutting it down to"<<num<<endl;

        actions++;

        if (fd==1)
        {
            break;
        }
        fd--;
    }

    ans=solve(prenum,num);

    ret.ac=actions+ans.ac;
    ret.tn=ans.tn;

    if (onum<=1000000)
    mem[prenum][onum]=ret;

    return ret;
}

int main()
{
    Int n;
    r ans;
    Int i,j;

    Int cp,dig;
    bool first;

    for (i=0;i<=9;i++)
    {
        for (j=0;j<=1000000;j++)
        {
            mem[i][j].ac=-1;
        }
    }

    scanf("%I64d",&n);

    if (n==0)
    {
        printf("0\n");
        return 0;
    }

    ans=solve(0,n);

    printf("%I64d\n",ans.ac);

    return 0;
}