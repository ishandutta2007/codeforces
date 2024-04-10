#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector< pair<int,int> > voters[100001];
vector< pair<int,int> > musttakehere[100001];

int guyscost[100001];
int status[100001]; ///0 - not taken | 1 - volunteered | 2 - forced

int curspent;

set< pair<int,int> > forced;
set< pair<int,int> > volunteers;
set< pair<int,int> >::iterator myit;

bool CheckStatus(int votes)
{
    if (forced.size()>votes)
    return false;

    int curtaken=(int)forced.size()+(int)volunteers.size();

    while(curtaken>votes)
    {
        myit=volunteers.end();
        myit--;

        status[ (*myit).second ]=0;
        curspent-=(*myit).first;

        //cout<<"Relasing volunteer "<<(*myit).second<<" with cost "<<(*myit).first<<endl;

        volunteers.erase(myit);

        curtaken--;
    }

    return true;
}

int main()
{
    int i,j;
    int votefor,cost;
    int bestspent=1999999999;
    pair<int,int> cur;
    bool terminate;
    int myvotes=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&votefor,&cost);

        guyscost[i]=cost;

        voters[votefor].push_back(make_pair(cost,i));
    }

    for (i=0;i<=100000;i++)
    {
        sort(voters[i].begin(),voters[i].end());
        reverse(voters[i].begin(),voters[i].end());
    }

    for (i=0;i<=100000;i++)
    {
        for (j=(int)voters[i].size()-1;j>=0;j--)
        {
            musttakehere[j+1].push_back(voters[i][j]);
        }
    }

    for (i=1;i<=100000;i++)
    {
        sort(musttakehere[i].begin(),musttakehere[i].end());
    }

    curspent=0;
    for (i=1;i<=n;i++)
    {
        curspent+=guyscost[i];
        status[i]=1;
        volunteers.insert( make_pair(guyscost[i],i) );
    }

    bestspent=curspent;
    //cout<<"Spending "<<bestspent<<endl;

    terminate=false;
    for (i=100000;i>=1;i--)
    {
        //cout<<i<<" and "<<musttakehere[i].size()<<endl;
        for (j=0;j<musttakehere[i].size();j++)
        {
            cur=musttakehere[i][j];

            //cout<<"Forcing "<<cur.second<<" (of cost "<<cur.first<<") inside"<<endl;

            if (status[cur.second]==0) ///not taken
            {
                //cout<<"He was inact1ive"<<endl;

                forced.insert( make_pair(cur.first,cur.second) );

                status[cur.second]=2;

                curspent+=cur.first;
            }
            else if (status[cur.second]==1) ///volunteer
            {
                //cout<<"He was a volunteer"<<endl;

                myit=volunteers.find( make_pair(cur.first,cur.second) );
                volunteers.erase(myit);

                forced.insert( make_pair(cur.first,cur.second) );

                status[cur.second]=2;
            }

            //cout<<"Cleaning"<<endl;

            if (!CheckStatus(i))
            {
                terminate=true;
                break;
            }

            //cout<<"New cost = "<<curspent<<endl;
        }

        if (!CheckStatus(i))
        {
            terminate=true;
            break;
        }

        if (terminate)
        break;

        if (curspent<bestspent)
        {
            bestspent=curspent;
        }
    }

    printf("%d\n",bestspent);

    return 0;
}