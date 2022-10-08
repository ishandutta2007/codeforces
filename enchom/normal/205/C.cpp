#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long Int;

Int Digits(Int k)
{
    Int dig=0;
    
    if (k==0)
    return 1;
    
    while (k>0)
    {
        k=k/10;
        dig++;
    }
    return dig;
}

Int POWER(Int k,Int p)
{
    Int i,num=1;
    for (i=1;i<=p;i++)
    num=num*k;
    
    return num;
}

Int GetAll(Int str,Int end)
{
    Int ans=0,i,j;
    Int digs=Digits(str);
    Int down,up;
    Int copy1=str,copy2=end;
    Int digited1[20],digited2[20];
    bool flag=false;
    
    for (i=digs;i>=1;i--)
    {
        digited1[i]=copy1%10;
        copy1=copy1/10;
        digited2[i]=copy2%10;
        copy2=copy2/10;
    }
    if (digs==1)
    {
        for (i=str;i<=end;i++)
        {
            ans++;
        }
        return ans;
    }
    
    for (i=digited1[1];i<=digited2[1];i++)
    {
        if ( i>digited1[1] && i<digited2[1] )
        {
            ans=ans+POWER(10,digs-2);
        }
        else
        {
            up=0;
            for (j=1;j<=digs-1;j++)
            up=up*10+9;
            
            down=0;
            
            if (i==digited1[1])
            {
                for (j=2;j<=digs;j++)
                {
                    down=down*10+digited1[j];
                }
            }
            if (i==digited2[1])
            {
                up=0;
                for (j=2;j<=digs;j++)
                {
                    up=up*10+digited2[j];
                }
            }
            flag=false;
            while(up%10!=i)
            {
                up--;
                if (up<down)
                {
                    flag=true;
                    break;
                }
            }
            if (flag)
            continue;
            while(down%10!=i)
            {
                down++;
                if (down>up)
                {
                    flag=true;
                    break;
                }
            }
            if (flag)
            continue;
            
            down=down/10;
            up=up/10;
            
            if (up<down)
            continue;
            
            ans=ans+(up-down+1);
        }
    }
    return ans;
}

int main()
{
    Int l,r;
    Int endnum,startnum;
    Int ans=0;
    Int k;
    
    cin>>l>>r;
    
    if (Digits(l)==Digits(r))
    {
        ans=GetAll(l,r);
    }
    else
    {
        endnum=POWER(10,Digits(l))-1;
        ans=ans+GetAll(l,endnum);
        k=Digits(l);
        startnum=POWER(10,k);
        endnum=POWER(10,k+1)-1;
        while (Digits(startnum)!=Digits(r))
        {
            ans=ans+GetAll(startnum,endnum);
            k++;
            startnum=POWER(10,k);
            endnum=POWER(10,k+1)-1;
        }
        ans=ans+GetAll(startnum,r);
    }
    cout<<ans<<endl;
    return 0;
}