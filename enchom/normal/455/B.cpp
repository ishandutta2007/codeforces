#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int Trie[110001][31];
int kids[110001];
int verctr=1;
int n,k;
char inp[110001];
int L=0;
bool W[110001];
bool LI[110001];

void AddToTrie()
{
    int cur=1;
    int i;
    int letter;

    for (i=1;i<=L;i++)
    {
        letter=inp[i]-'a';

        if (Trie[cur][letter]==0)
        {
            verctr++;
            Trie[cur][letter]=verctr;
            kids[cur]++;
            cur=verctr;
        }
        else
        {
            cur=Trie[cur][letter];
        }
    }

    return;
}

bool WinPos(int ver)
{
    int i;
    bool won=false;

    if (kids[ver]==0)
    {
        W[ver]=false;
        return false;
    }

    for (i=0;i<=25;i++)
    {
        if (Trie[ver][i]!=0)
        {
            if (!WinPos(Trie[ver][i]))
            {
                won=true;
            }
        }
    }

    W[ver]=won;

    return won;
}

bool LoseIntPos(int ver)
{
    int i;
    bool loseint=false;

    if (kids[ver]==0)
    {
        LI[ver]=true;
        return true;
    }

    for (i=0;i<=25;i++)
    {
        if (Trie[ver][i]!=0)
        {
            if (!LoseIntPos(Trie[ver][i]))
            {
                loseint=true;
            }
        }
    }

    LI[ver]=loseint;

    return loseint;
}

int main()
{
    int i;

    memset(Trie,0,sizeof(Trie));
    memset(kids,0,sizeof(kids));

    scanf("%d %d",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%s",inp+1);
        L=strlen(inp+1);

        AddToTrie();
    }

    WinPos(1);
    LoseIntPos(1);

    if (!W[1]) ///L
    {
        printf("Second\n");
    }
    else if (LI[1])
    {
        printf("First\n");
    }
    else
    {
        if (k%2==0)
        printf("Second\n");
        else
        printf("First\n");
    }

    return 0;
}