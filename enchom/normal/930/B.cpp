#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
typedef long double ldouble;
char words[5111][5111];
int n;

vector<int> firstLet[27];
int ctr[27];

ldouble solveLetter(int x)
{
    int i,j;
    int uniq;
    int let;
    int bestuniq=0;

    for (i=2;i<=n;i++)
    {
        memset(ctr,0,sizeof(ctr));
        uniq=0;

        for (j=0;j<firstLet[x].size();j++)
        {
            let=words[ firstLet[x][j] ][i]-'a';

            if (ctr[let]==0)
                uniq++;
            else if (ctr[let]==1)
                uniq--;

            ctr[let]++;
        }

        if (uniq>bestuniq)
            bestuniq=uniq;
    }

    //cout<<"Best unique for letter "<<x<<" is "<<bestuniq<<endl;

    return (ldouble)bestuniq/(ldouble)(firstLet[x].size());
}

int main()
{
    int i,j;
    int L;
    ldouble ans=0.0;

    scanf("%s",words[1]+1);
    n=strlen(words[1]+1);

    for (i=2;i<=n;i++)
    {
        L=0;

        for (j=i;j<=n;j++)
        {
            L++;
            words[i][L]=words[1][j];
        }

        for (j=1;j<i;j++)
        {
            L++;
            words[i][L]=words[1][j];
        }
    }

    for (i=1;i<=n;i++)
    {
        firstLet[ words[i][1]-'a' ].push_back(i);
    }

    for (i=0;i<=26;i++)
    {
        if (!firstLet[i].empty())
            ans += solveLetter(i) * ( (ldouble)firstLet[i].size() / (ldouble)n );
    }

    printf("%.8f\n",(double)ans);

    return 0;
}