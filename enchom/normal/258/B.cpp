#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int LL=0;
Int LuckyNums[2001];

Int totalnums;

Int mycontainer[10]={0,0,0,0,0,0,0,0,0,0};

Int Digitizor[10];
Int MDIG[10];

Int breaker[10001][7];
Int bL;

Int tempfill[7];

Int local[7];

Int guysgot[10];

const Int MOD=1000000007;

void Generator(Int leftdigs,Int num)
{
    if (leftdigs==0)
    {
        LL++;
        LuckyNums[LL]=num;
        return;
    }
    else
    {
        Generator(leftdigs-1,num*10+4);
        Generator(leftdigs-1,num*10+7);
    }
}

Int Digs(Int k)
{
    Int ctr=0;
    
    if (k==0)
    return 1;
    
    while(k>0)
    {
        ctr++;
        k=k/10;
    }
    return ctr;
}

void GetNums( Int luckers,Int mustuse,bool smaller,Int waystogethere,Int leftdigs,Int digfill )
{
    ///cout<<"Trying with "<<luckers<<" lucky nums, mustuse "<<mustuse<<" our num is "<<smaller<<" than m,there are "<<waystogethere<<" ways/"<<leftdigs<<" left digits and "<<digfill<<"filled digits"<<endl;
    
    Int x,i;
    Int smallershit=0;
        
    if (waystogethere==0)
    return;
    
    if (leftdigs==0)
    {
        mycontainer[luckers]+=waystogethere;
        return;
    }
    ///Useless check
    if (leftdigs-(luckers-mustuse+1)<0)
    {
        return;
    }
    
    
    ///Call 1, choose nextnum
    if (mustuse<=luckers && leftdigs-(luckers-mustuse+1)==0)
    {
        if (smaller)
        GetNums( luckers,mustuse+1,true,waystogethere,leftdigs-1,digfill+1 );
        else
        {
            if (Digitizor[mustuse]<MDIG[digfill])
            {
                GetNums( luckers,mustuse+1,true,waystogethere,leftdigs-1,digfill+1 );
            }
            else if (Digitizor[mustuse]==MDIG[digfill])
            {
                ///cout<<Digitizor[mustuse]<<" "<<MDIG[digfill]<<endl;
                ///cout<<"dont tell me"<<endl;
                GetNums( luckers,mustuse+1,false,waystogethere,leftdigs-1,digfill+1 );
            }
        }
        
        return;
    }
    
    
    if (mustuse<=luckers)
    {
        if (smaller)
        GetNums( luckers,mustuse+1,true,waystogethere,leftdigs-1,digfill+1 );
        else
        {
            if (Digitizor[mustuse]<MDIG[digfill])
            {
                GetNums( luckers,mustuse+1,true,waystogethere,leftdigs-1,digfill+1 );
            }
            else if (Digitizor[mustuse]==MDIG[digfill])
            {
                GetNums( luckers,mustuse+1,false,waystogethere,leftdigs-1,digfill+1 );
            }
        }
    }

    if (smaller)
    {
        if (totalnums==leftdigs)
            x=7;
        else
            x=8;
        
        GetNums( luckers,mustuse,true,waystogethere*x,leftdigs-1,digfill=1 );
    }
    else
    {
        if (totalnums==leftdigs)
            x=1;
        else
            x=0;
        
        smallershit=0;
        for (i=x;i<=9;i++)
        {
            if (i==7 || i==4)
            continue;
            
            if (MDIG[digfill]>i)
            {
                smallershit++;
            }
            else if (MDIG[digfill]==i)
            {
                GetNums( luckers,mustuse,false,waystogethere,leftdigs-1,digfill+1 );
            }
            else
            break;
        }
        GetNums( luckers,mustuse,true,waystogethere*smallershit,leftdigs-1,digfill+1 );
    }
    return;
}

void BrakeNum(Int barrier,Int cursum,Int leftdigs,Int filldig,Int lastnum)
{
    Int i;
    
    if (leftdigs==0)
    {
        bL++;
        for (i=1;i<=6;i++)
        {
            breaker[bL][i]=tempfill[i];
        }
        return;
    }
    
    for (i=lastnum;i<=9;i++)
    {
        if (cursum+i<barrier)
        {
            tempfill[filldig]=i;
            BrakeNum(barrier,cursum+i,leftdigs-1,filldig+1,i);
        }
    }
}

int main()
{
    Int i,j,in,ja;
    Int m;
    Int copy;
    Int thisone;
    Int total=0;
    bool wasmax;
    
    scanf("%I64d",&m);
    
    if (m==1000000000)
    {
        wasmax=true;
        m--;
    }
    else
    wasmax=false;
    
    copy=m;
    for (i=Digs(m);i>=1;i--)
    {
        MDIG[i]=copy%10;
        copy=copy/10;
    }
    
    for (i=1;i<=9;i++)
    {
        Generator(i,0);
    }
    for (i=1;i<=LL;i++)
    {
        if (Digs(LuckyNums[i])==9 && LuckyNums[i]<=m)
        {
            mycontainer[9]++;
        }
    }
    for (i=1;i<=LL;i++)
    {
        if (Digs(LuckyNums[i])==9)
        continue;
        
        copy=LuckyNums[i];
        for (j=Digs(LuckyNums[i]);j>=1;j--)
        {
            
            Digitizor[j]=copy%10;
            copy=copy/10;
        }
        
        for (j=Digs(LuckyNums[i]);j<=Digs(m);j++)
        {
            ///cout<<"trying num "<<LuckyNums[i]<<" "<<"to be"<<j<<" digited"<<endl;
            ///cout<<mycontainer[2]<<" .b"<<endl;
            totalnums=j;
            if (j==Digs(m))
            GetNums( Digs(LuckyNums[i]),1,false,1,j,1 );
            else
            GetNums( Digs(LuckyNums[i]),1,true,1,j,1 );
            
            ///cout<<mycontainer[2]<<endl;
        }
    }
    for (i=1;i<=Digs(m);i++)
    {
        totalnums=i;
        if (i==Digs(m))
        GetNums( 0,1,false,1,i,1 );
        else
        GetNums( 0,1,true,1,i,1 );
    }
    ///cout<<mycontainer[0]<<endl;
    ///cout<<mycontainer[1]<<endl;
    ///cout<<mycontainer[2]<<endl;
    
    if (wasmax)
    mycontainer[0]++;
    
    for (i=1;i<=9;i++)
    {
        if (mycontainer[i]==0)
        continue;
        
        bL=0;
        BrakeNum(i,0,6,1,0);
        
        for (j=1;j<=bL;j++)
        {
            for (in=1;in<=6;in++)
            {
                local[in]=breaker[j][in];
            }
            
            sort(local+1,local+7);
            do
            {
                for (in=0;in<=9;in++)
                {
                    guysgot[in]=0;
                }
                
                for (in=1;in<=6;in++)
                {
                    guysgot[ local[in] ]++;
                }
                thisone=1;
                
                for (in=0;in<=9;in++)
                {
                    for (ja=mycontainer[in];ja>=mycontainer[in]-guysgot[in]+1;ja--)
                    {
                        thisone=( thisone*(ja%MOD) )%MOD;
                    }
                }
                
                thisone=(thisone*(mycontainer[i]%MOD))%MOD;
                
                total=(total+thisone)%MOD;
            }while( next_permutation(local+1,local+7) );
        }
    }
    
    printf("%I64d\n",total);
    
    return 0;
}