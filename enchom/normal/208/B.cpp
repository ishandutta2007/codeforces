#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int cards[53];
bool possible[53][53][53][53];

int main()
{
    Int n;
    Int i,j,in,ja;
    char num,color;
    Int dnum,dcolor;
    Int fnum,fcolor;
    Int card;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        cin>>num>>color;
        
        if (num>='0' && num<='9')
        card=num-'0';
        else
        {
            if (num=='T')
            card=10;
            if (num=='J')
            card=11;
            if (num=='Q')
            card=12;
            if (num=='K')
            card=13;
            if (num=='A')
            card=1;
        }
        
        if (color=='D')
        card=card+13;
        if (color=='H')
        card=card+26;
        if (color=='C')
        card=card+39;
        
        cards[i]=card;
    }
    
    
    for (i=0;i<=52;i++)
    {
        for (j=0;j<=52;j++)
        {
            for (in=0;in<=52;in++)
            {
                for (ja=0;ja<=52;ja++)
                {
                    possible[i][j][in][ja]=false;
                }
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            for (in=1;in<=n;in++)
            {
                if (cards[in]%13!=0)
                dnum=cards[in]%13;
                else
                dnum=13;
                        
                if (cards[in]%13!=0)
                dcolor=cards[in]/13;
                else
                dcolor=cards[in]/13-1;
                
                ///
                
                if (cards[j]%13!=0)
                fnum=cards[j]%13;
                else
                fnum=13;
                        
                if (cards[j]%13!=0)
                fcolor=cards[j]/13;
                else
                fcolor=cards[j]/13-1;
                
                ///
                
                if (cards[i]%13!=0)
                num=cards[i]%13;
                else
                num=13;
                        
                if (cards[i]%13!=0)
                color=cards[i]/13;
                else
                color=cards[i]/13-1;
                
                //cout<<cards[i]<<" "<<cards[j]<<" "<<cards[in];
                if ( (dcolor==fcolor || dnum==fnum) && (dcolor==color || dnum==num) )
                {
                    //cout<<" is true"<<endl;
                    possible[0][cards[i]][cards[j]][cards[in]]=true;
                }
                else
                {
                   // cout<<" is false"<<endl;
                    possible[0][cards[i]][cards[j]][cards[in]]=false;
                }
            }
        }
    }
    
    if (n<=3)
    {
        if (n==3)
        {
            if (possible[0][cards[1]][cards[2]][cards[3]])
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if (n==2)
        {
            if (cards[2]%13!=0)
            dnum=cards[2]%13;
            else
            dnum=13;
                        
            if (cards[2]%13!=0)
            dcolor=cards[2]/13;
            else
            dcolor=cards[2]/13-1;
                
                ///
                
            if (cards[1]%13!=0)
            fnum=cards[1]%13;
            else
            fnum=13;
                        
            if (cards[1]%13!=0)
            fcolor=cards[1]/13;
            else
            fcolor=cards[1]/13-1;
            
            if (fcolor==dcolor || fnum==dnum)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
        else if (n==1)
        {
            printf("YES\n");
        }
    }
    else
    {
        for (i=1;i<=n-3;i++)
        {
            for (j=1;j<=n;j++)
            {
                for (in=1;in<=n;in++)
                {
                    for (ja=1;ja<=n;ja++)
                    {
                        possible[i][ cards[j] ][ cards[in] ][ cards[ja] ]=false;
                        
                        if (cards[ja]%13!=0)
                        dnum=cards[ja]%13;
                        else
                        dnum=13;
                        
                        if (cards[ja]%13!=0)
                        dcolor=cards[ja]/13;
                        else
                        dcolor=cards[ja]/13-1;
                        
                        if (cards[in]%13!=0)
                        fnum=cards[in]%13;
                        else
                        fnum=13;
                        
                        if (cards[in]%13!=0)
                        fcolor=cards[in]/13;
                        else
                        fcolor=cards[in]/13-1;
                        
                        if (fcolor==dcolor || fnum==dnum)
                        {
                            if ( possible[i-1][cards[i]][cards[j]][cards[ja]] )
                            {
                                possible[i][ cards[j] ][ cards[in] ][ cards[ja] ]=true;
                                continue;
                            }
                        }
                        
                        if (cards[i]%13!=0)
                        fnum=cards[i]%13;
                        else
                        fnum=13;
                        
                        if (cards[i]%13!=0)
                        fcolor=cards[i]/13;
                        else
                        fcolor=cards[i]/13-1;
                        
                        if (fcolor==dcolor || fnum==dnum)
                        {
                            if ( possible[i-1][cards[ja]][cards[j]][cards[in]] )
                            {
                                possible[i][ cards[j] ][ cards[in] ][ cards[ja] ]=true;
                                continue;
                            }
                        }
                    }
                }
            }
        }
        if (possible[n-3][ cards[n-2] ][ cards[n-1] ][ cards[n] ])
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}