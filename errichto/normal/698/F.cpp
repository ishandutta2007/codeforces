#include <bits/stdc++.h>
using namespace std;

inline void nope()
{
    printf("0\n");
    exit(0);
}

int n;
int tab[1000007];

int sito[1000007];
int ory[1000007];

long long wyn=1;
long long mod=1000000007;

vector <int> wek[1000007];

int cozam[1000007];
int zakl[1000007];

int ile[1000007];

inline void domnsil(int v)
{
    for (int i=1; i<=v; i++)
    {
        wyn*=i;
        wyn%=mod;
    }
}

inline int f(int v)
{
    if (v==1)
    return 1;
    return n/v;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    scanf("%d", &tab[i]);

    sito[1]=1;
    ory[1]=1;
    for (int i=1; i<=n; i++)
    {
        if (!sito[i])
        {
            for (int j=i; j<=n; j+=i)
            {
                sito[j]=i;
            }
        }
        ory[i]=ory[i/sito[i]];
        if (ory[i]%sito[i])
        ory[i]*=sito[i];
    }
    for (int i=1; i<=n; i++)
    {
        if (sito[i]==i)
        {
            wek[f(i)].push_back(i);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (wek[i].empty())
        continue;
        if (wek[i].size()==1)
        {
            int x=wek[i][0];
            for (int j=x; j<=x*i; j+=x)
            {
                if (tab[j]%x)
                {
                    nope();
                }
            }
            continue;
        }
        int jes=wek[i].size();
        for (int j=0; j<wek[i].size(); j++)
        {
            int x=wek[i][j];
            for (int l=x; l<=x*i; l+=x)
            {
                if (!tab[l])
                continue;
                int pie=sito[tab[l]];
                if (f(pie)!=i)
                nope();
                if (!cozam[x] && !zakl[pie])
                {
                    cozam[x]=pie;
                    zakl[pie]=x;
                    jes--;
                }
                if (cozam[x]!=pie || zakl[pie]!=x)
                nope();
            }
        }
        domnsil(jes);
    }
    for (int i=1; i<=n; i++)
    ile[ory[i]]++;
    for (int i=1; i<=n; i++)
    ile[ory[tab[i]]]--;
    for (int i=1; i<=n; i++)
    domnsil(ile[i]);
    printf("%lld\n", wyn);
	return 0;
}