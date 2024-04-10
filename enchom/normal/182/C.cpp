#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
typedef long long Int;

struct number
{
    Int orgind;
    Int val;

    bool operator<( const number& other) const
    {
        if (val<other.val)
        return true;
        else if (val>other.val)
        return false;
        else
        {
            return orgind<other.orgind;
        }
    }
};

Int n,len,k;
Int nums[100001];
set<number> waiting;
set<number> covered;
set<number>::iterator myit,myit2;
Int status[100001];
Int cursum=0;
Int maxsum=0;

void PushQueue()
{
    number help;

    ///cout<<"Calling push_queue function"<<endl;

    if (waiting.size()>0)
    {
        myit=waiting.begin();

        ///cout<<"Pushing value = "<<(*myit).val<<" thats at index "<<(*myit).orgind<<endl;

        status[ (*myit).orgind ]=2;

        help.val=(*myit).val;
        help.orgind=(*myit).orgind;

        waiting.erase(myit);
        covered.insert(help);

        cursum=cursum-2*help.val;
    }

    ///cout<<"Sum at the end = "<<cursum<<endl;

    return;
}

void Add(Int ind)
{
    number help,help2;

    ///cout<<"Adding number "<<ind<<endl;

    if (nums[ind]>=0)
    {
        ///cout<<"Its positive"<<endl;
        status[ind]=0;
        cursum=cursum+nums[ind];
        ///cout<<"Sum="<<cursum<<endl;
    }
    else
    {
        help.val=nums[ind];
        help.orgind=ind;

        ///cout<<"Its negative"<<endl;

        cursum=cursum+nums[ind];

        ///cout<<"Midsum="<<cursum<<endl;

        waiting.insert(help);
        status[ind]=1;

        if (covered.size()<k)
        {
            ///cout<<"Theres still space"<<endl;
            PushQueue();
        }
        else
        {
            if (k==0)
            return;

            ///cout<<"No space, let's try to swap"<<endl;

            myit=waiting.begin();

            myit2=covered.end();
            myit2--;

            ///cout<<"Worst from covered = "<<(*myit2).val<<" at index "<<(*myit2).orgind<<endl;
            ///cout<<"Best from waiting = "<<(*myit).val<<" at index "<<(*myit).orgind<<endl;


            if ( (*myit).val<(*myit2).val )
            {
                ///cout<<"Initiating swap"<<endl;

                help.val=(*myit).val;
                help.orgind=(*myit).orgind;

                help2.val=(*myit2).val;
                help2.orgind=(*myit2).orgind;

                cursum=cursum+2*(*myit2).val;
                cursum=cursum-2*(*myit).val;

                waiting.erase(myit);
                covered.erase(myit2);

                waiting.insert(help2);
                covered.insert(help);

                status[help2.orgind]=1;
                status[help.orgind]=2;
            }

            ///cout<<"Ending sum = "<<cursum<<endl;
        }
    }
}

void Remove(Int ind)
{
    number help;

    ///cout<<"Removing "<<ind<<endl;

    if (status[ind]==0) ///Non-negative number
    {
        ///cout<<"Its positive"<<endl;
        cursum-=nums[ind];
        ///cout<<"Sum="<<cursum<<endl;
    }
    else if (status[ind]==1) ///Waiting in the queue
    {
        ///cout<<"It's in the queue"<<endl;

        help.val=nums[ind];
        help.orgind=ind;

        cursum=cursum-nums[ind];

        waiting.erase(help);
    }
    else ///Is actually covered
    {
        ///cout<<"It was covered"<<endl;

        help.val=nums[ind];
        help.orgind=ind;

        cursum=cursum+nums[ind];

        covered.erase(help);

        PushQueue();
    }
}

int main()
{
    Int i;

    scanf("%I64d %I64d",&n,&len);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&nums[i]);
    }

    scanf("%I64d",&k);

    for (i=1;i<=len;i++)
    {
        Add(i);
    }

    if (cursum>maxsum)
    {
        maxsum=cursum;
    }

    for (i=len+1;i<=n;i++)
    {
        Remove(i-len);
        Add(i);

        if (cursum>maxsum)
        {
            maxsum=cursum;
        }
    }

    ///

    waiting.clear();
    covered.clear();
    cursum=0;
    for (i=1;i<=n;i++)
    {
        nums[i]*=-1;
    }

    ///

    ///cout<<endl<<"Second try"<<endl<<endl;

    for (i=1;i<=len;i++)
    {
        Add(i);
    }

    if (cursum>maxsum)
    {
        maxsum=cursum;
    }

    for (i=len+1;i<=n;i++)
    {
        Remove(i-len);
        Add(i);

        if (cursum>maxsum)
        {
            maxsum=cursum;
        }
    }

    printf("%I64d\n",maxsum);

    return 0;
}