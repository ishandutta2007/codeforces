#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
using namespace std;
typedef long long Int;

Int A;
const Int Keeping=10000;
Int Seen[Keeping+1];

Int S_F(Int k)
{
    Int c=45LL;
    Int multiplier=1;
    Int ld;
    Int ans=0;
    Int rest_num=0;

    while(k>0)
    {
        ld=k%10;
        k/=10;

        ans+=( ( (k%A)*c )%A ) * multiplier;
        ans%=A;

        ld--;
        ans+=( ( (ld*(ld+1LL))/2LL )%A ) * multiplier;
        ans%=A;
        ld++;

        ans+=ld*(rest_num+1);

        ans%=A;

        rest_num=rest_num+multiplier*ld;

        multiplier*=10;
        multiplier%=A;
    }

    return ans;
}

Int S(Int k)
{
    Int ans=0;
    Int i;
    Int cp;

    for (i=1;i<=k;i++)
    {
        cp=i;

        while(cp>0)
        {
            ans+=cp%10;
            cp/=10;
        }

        ans%=A;
    }

    return ans;
}

bool LookForMatch(Int num)
{
    Int val;

    while(1)
    {
        val=S_F(num);

        if (val>Keeping)
        return false;

        ///cout<<"Adding"<<rand()<<endl;

        if (val==0)
        {
            printf("1 %I64d\n",num);
            return true;
        }

        if (Seen[val]!=-1)
        {
            if (Seen[val]<=num)
            return false;

            printf("%I64d %I64d\n",Seen[val]+1,num);

            ///cout<<S_F(num)<<"-"<<S_F( Seen[val] )<<" = "<<S_F(num)-S_F( Seen[val] )<<endl;
            ///cout<<S(num)<<" "<<S( Seen[val] )<<endl;

            return true;
        }

        Seen[val]=num;

        num++;
    }

    return false;
}

int main()
{
    //freopen("test.txt","r",stdin);

    Int i;
    Int cur;
    Int BigJump;
    Int last_one;
    Int mark;
    Int l,r,mid,best;
    Int v;

    scanf("%I64d",&A);

    memset(Seen,-1,sizeof(Seen));

    BigJump=(A-2*Keeping)/900LL;
    if (BigJump<=0)
    BigJump=1;

    last_one=1;
    cur=1;

    while(1)
    {
        //cout<<"Calling for "<<cur<<endl;
        if ( LookForMatch(cur) )
        break;

        if (BigJump>1)
        {
            if (S_F(cur)<S_F(last_one))
            {
                l=last_one;
                r=cur;

                while(l<=r)
                {
                    mid=(l+r)/2;

                    v=S_F(mid);

                    if (v<=S_F(cur))
                    {
                        r=mid-1;
                    }
                    else
                    {
                        l=mid+1;
                        best=mid;
                    }
                }

                cur=best+1;
                ///cout<<"Going for a special match "<<endl;
                //cout<<"Calling for "<<cur<<endl;
                if (LookForMatch(cur))
                {
                    return 0;
                }
            }
        }

        last_one=cur;
        cur+=BigJump;
    }

    return 0;
}