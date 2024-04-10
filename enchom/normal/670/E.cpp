#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char seq[500111];
int n,m,p;
char q[500111];

int st[500111];
int sL=0;
int ctr=0;

int id[500111];
int pv[500111];
int nxt[500111];

void Remove(int k)
{
    nxt[ pv[k] ]=nxt[k];
    pv[ nxt[k] ]=pv[k];

    return;
}

int main()
{
    int i,j;
    int cur;
    int remid;

    scanf("%d %d %d",&n,&m,&p);

    scanf("%s",seq+1);

    nxt[0]=1;
    for (i=1;i<=n;i++)
    {
        pv[i]=i-1;
        nxt[i]=i+1;

        if (seq[i]=='(')
        {
            ctr++;

            id[i]=ctr;

            sL++;
            st[sL]=ctr;
        }
        else
        {
            id[i]=st[sL];
            sL--;
        }
    }

    scanf("%s",q+1);

    cur=p;

    for (i=1;i<=m;i++)
    {
        if (q[i]=='R')
        {
            cur=nxt[cur];
        }
        else if (q[i]=='L')
        {
            cur=pv[cur];
        }
        else
        {
            remid=id[cur];

            if (seq[cur]=='(')
            {
                do
                {
                    Remove(cur);

                    cur=nxt[cur];
                }while( id[cur]!=remid );

                Remove(cur);

                if (nxt[cur]==n+1)
                cur=pv[cur];
                else
                cur=nxt[cur];
            }
            else
            {
                do
                {
                    Remove(cur);

                    cur=pv[cur];
                }while( id[cur]!=remid );

                Remove(cur);

                if (nxt[cur]==n+1)
                cur=pv[cur];
                else
                cur=nxt[cur];
            }
        }
    }

    cur=nxt[0];

    while(cur!=n+1)
    {
        printf("%c",seq[cur]);
        cur=nxt[cur];
    }

    printf("\n");

    return 0;
}