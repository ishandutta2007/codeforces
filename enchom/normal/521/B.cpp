#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
typedef long long Int;
#define MOD 1000000009LL

map< int,pair<int,int> > Removable;
map< int,pair<int,int> >::iterator rit;
map< pair<int,int>,int > Active;
map< pair<int,int>,int >::iterator myit;

int n;
pair<int,int> Cubes[100011];

int ObCounter[100011];

vector<int> Ans;

vector<int> Below[100011];
vector<int> Above[100011];
bool InRemovable[100011];
bool Removed[100011];

int Bases(int k)
{
    int i;
    int ans=0;

    for (i=0;i<Below[k].size();i++)
    {
        if (!Removed[ Below[k][i] ])
        {
            ans++;
        }
    }

    return ans;
}

bool IsRemovable(int k)
{
    if (Removed[k])
    return false;

    int i;

    for (i=0;i<Above[k].size();i++)
    {
        if (Removed[ Above[k][i] ])
        continue;

        if (Bases(Above[k][i])==1)
        {
            //cout<<"fucking with "<<k<<endl;
            //cout<<"Bases of "<<Above[k][i]<<" are "<<Bases(Above[k][i])<<endl;
            return false;
        }
    }

    return true;
}

void CheckKids(int k)
{
    int i;

    for (i=0;i<Below[k].size();i++)
    {
        if (!Removed[ Below[k][i] ])
        {
            if (IsRemovable( Below[k][i] ))
            {
                if (!InRemovable[ Below[k][i] ])
                {
                    Removable.insert( make_pair(Below[k][i]-1,Cubes[ Below[k][i] ]) );
                    InRemovable[ Below[k][i] ]=true;

                    //cout<<Below[k][i]<<" is now removable"<<endl;
                }
            }
            else
            {
                if (InRemovable[ Below[k][i] ])
                {
                    Removable.erase(Below[k][i]-1);
                    InRemovable[ Below[k][i] ]=false;

                    //cout<<Below[k][i]<<" isnt removable anymore"<<endl;
                }
            }
        }
    }

    return;
}

int main()
{
    //freopen("sample.txt","r",stdin);

    int i,j;
    int maximizing=1;
    int X,Y,id;
    Int Answer=0;
    Int multi=1;
    bool bad;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&Cubes[i].first,&Cubes[i].second);

        Active.insert( make_pair(Cubes[i],i-1) );
    }

    for (i=1;i<=n;i++)
    {
        myit=Active.find( make_pair(Cubes[i].first-1,Cubes[i].second+1) );
        if (myit!=Active.end())
        {
            Above[i].push_back( (*myit).second+1 );
            Below[ (*myit).second+1 ].push_back(i);
        }

        myit=Active.find( make_pair(Cubes[i].first,Cubes[i].second+1) );
        if (myit!=Active.end())
        {
            Above[i].push_back( (*myit).second+1 );
            Below[ (*myit).second+1 ].push_back(i);
        }

        myit=Active.find( make_pair(Cubes[i].first+1,Cubes[i].second+1) );
        if (myit!=Active.end())
        {
            Above[i].push_back( (*myit).second+1 );
            Below[ (*myit).second+1 ].push_back(i);
        }
    }

    for (i=1;i<=n;i++)
    {
        bad=false;
        for (j=0;j<Above[i].size();j++)
        {
            if ( Below[ Above[i][j] ].size()==1 )
            {
                bad=true;
                break;
            }
        }

        if (!bad)
        {
            Removable.insert( make_pair(i-1,Cubes[i]) );
            InRemovable[i]=true;

            //cout<<i<<" is Removable"<<endl;
        }
    }

    while(!Removable.empty())
    {
        if (maximizing)
        {
            rit=Removable.end();
            rit--;
        }
        else
        {
            rit=Removable.begin();
        }

        Ans.push_back( (*rit).first );

        X=(*rit).second.first;
        Y=(*rit).second.second;
        id=(*rit).first+1;

        //cout<<"Choosing "<<id<<endl;

        Removed[id]=true;

        for (i=0;i<Below[id].size();i++)
        {
            if (Removed[ Below[id][i] ])
            continue;

            if (IsRemovable(Below[id][i]))
            {
                if (!InRemovable[ Below[id][i] ])
                {
                    Removable.insert( make_pair(Below[id][i]-1,Cubes[ Below[id][i] ]) );
                    InRemovable[ Below[id][i] ]=true;

                    //cout<<"Adding "<<Below[id][i]<<" to removables"<<endl;
                }
            }
            else
            {
                if (InRemovable[Below[id][i]])
                {
                    Removable.erase(Below[id][i]-1);
                    InRemovable[ Below[id][i] ]=false;

                    //cout<<Below[id][i]<<" is no longer removable"<<endl;
                }
            }
        }

        for (i=0;i<Above[id].size();i++)
        {
            if (!Removed[ Above[id][i] ])
            CheckKids(Above[id][i]);
        }

        maximizing^=1;

        Removable.erase(rit);
    }

    for (i=(int)Ans.size()-1;i>=0;i--)
    {
        Answer=Answer+(Int)Ans[i]*multi;
        multi*=n;
        Answer%=MOD;
        multi%=MOD;
    }

    printf("%lld\n",Answer);

    return 0;
}