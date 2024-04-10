#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

string S1,S2;
string repost;
int n;
map<string,int> SM;
map<string,int>::iterator myit;

vector<int> Graph[10001];

void Decap()
{
    int i;

    for (i=0;i<S1.length();i++)
    {
        if (S1[i]>='A' && S1[i]<='Z')
        {
            S1[i]=S1[i]-'A'+'a';
        }
    }

    for (i=0;i<S2.length();i++)
    {
        if (S2[i]>='A' && S2[i]<='Z')
        {
            S2[i]=S2[i]-'A'+'a';
        }
    }

    return;
}

int deepest=0;

void DFS(int ver,int depth)
{
    if (depth>deepest)
    deepest=depth;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        DFS(Graph[ver][i],depth+1);
    }

    return;
}

int main()
{
    int i;
    int A,B;
    int counter=1;

    scanf("%d",&n);

    SM.insert(make_pair("polycarp",1));

    for (i=1;i<=n;i++)
    {
        cin>>S1>>repost>>S2;

        Decap();

        myit=SM.find(S1);
        if ( myit==SM.end() )
        {
            counter++;
            A=(*(SM.insert( make_pair(S1,counter) ).first)).second;
        }
        else
        A=(*myit).second;

        myit=SM.find(S2);
        if ( myit==SM.end() )
        {
            counter++;
            B=(*(SM.insert( make_pair(S2,counter) ).first)).second;
        }
        else
        B=(*myit).second;

        Graph[B].push_back(A);
    }

    DFS(1,1);

    printf("%d\n",deepest);

    return 0;
}