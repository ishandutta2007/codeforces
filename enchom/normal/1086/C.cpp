#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int t;
int n,k;
char s[1000111];
char a[1000111];
char b[1000111];

bool mapped[31];
int mapping[31];
int coremap[31];
bool coremapped[31];

void backUp()
{
    int i;

    for (i=0;i<=26;i++)
    {
        coremap[i] = mapping[i];
        coremapped[i] = mapped[i];
    }
}

void restore()
{
    int i;

    for (i=0;i<=26;i++)
    {
        mapping[i] = coremap[i];
        mapped[i] = coremapped[i];
    }
}

void fillTemplate()
{
    int i,j;

    for (i=0;i<k;i++)
    {
        if (mapping[i] == -1)
        {
            for (j=0;j<k;j++)
            {
                if (!mapped[j])
                {
                    mapped[j] = true;
                    mapping[i] = j;
                    break;
                }
            }
        }
    }

    return;
}

bool verifyTemplate()
{
    bool larger = false, smaller = false;
    int i;

    for (i=1;i<=n;i++)
    {
        int real = mapping[ s[i] - 'a' ];

        if (!larger)
        {
            if (real > a[i] - 'a')
                larger = true;
            else if (real < a[i] - 'a')
                return false;
        }

        if (!smaller)
        {
            if (real < b[i] - 'a')
                smaller = true;
            else if (real > b[i] - 'a')
                return false;
        }
    }

    return true;
}

bool smallTemplate(int ind)
{
    int i,j;

    for (i=ind;i<=n;i++)
    {
        if (mapping[ s[i]-'a' ] == -1)
        {
            for (j=0;j<k;j++)
            {
                if (!mapped[j])
                {
                    mapping[ s[i]-'a' ] = j;
                    mapped[j] = true;
                    break;
                }
            }
        }
    }

    fillTemplate();

    return verifyTemplate();
}

bool largeTemplate(int ind)
{
    int i,j;

    for (i=ind;i<=n;i++)
    {
        if (mapping[ s[i]-'a' ] == -1)
        {
            for (j=k-1;j>=0;j--)
            {
                if (!mapped[j])
                {
                    mapped[j] = true;
                    mapping[ s[i]-'a' ] = j;
                    break;
                }
            }
        }
    }

    fillTemplate();

    return verifyTemplate();
}

int main()
{
    int i,j;
    int test;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&k);
        scanf("%s",s+1);
        scanf("%s",a+1);
        scanf("%s",b+1);
        n = strlen(s+1);

        memset(mapping,-1,sizeof(mapping));
        memset(mapped,false,sizeof(mapped));

        int dif = n + 1;
        bool bad = false;
        for (i=1;i<=n;i++)
        {
            if (a[i] != b[i])
            {
                dif = i;
                break;
            }

            if (mapping[ s[i]-'a' ] != -1 && mapping[ s[i]-'a' ] != (a[i]-'a'))
            {
                bad = true;
                break;
            }

            if (mapped[ a[i]-'a' ] && mapping[ s[i]-'a' ] == -1)
            {
                bad = true;
                break;
            }

            mapping[ s[i]-'a' ] = a[i] - 'a';
            mapped[ a[i] - 'a' ] = true;
        }

        if (bad)
        {
            printf("NO\n");
            continue;
        }

        if (dif == n + 1)
        {
            fillTemplate();

            printf("YES\n");
            for (i=0;i<k;i++)
            {
                printf("%c",(char)(mapping[i]+'a'));
            }
            printf("\n");

            continue;
        }

        backUp();

        ///Larger first
        if (mapping[ s[dif]-'a' ] == -1 || mapping[ s[dif]-'a' ] > a[dif] - 'a')
        {
            bool done = false;

            if (mapping[ s[dif]-'a' ] == -1)
            {
                for (i=0;i<k;i++)
                {
                    if (!mapped[i] && i > a[dif] - 'a')
                    {
                        done = true;
                        mapping[ s[dif]-'a' ] = i;
                        mapped[i] = true;
                        break;
                    }
                }
            }
            else
            {
                done = true;
            }

            if (done)
            {
                if (smallTemplate(dif+1))
                {
                    printf("YES\n");
                    for (i=0;i<k;i++)
                    {
                        printf("%c",(char)(mapping[i]+'a'));
                    }
                    printf("\n");

                    continue;
                }
            }
        }

        restore();
        ///Smaller first
        if (mapping[ s[dif]-'a' ] == -1 || mapping[ s[dif]-'a' ] < b[dif] - 'a')
        {
            bool done = false;

            if (mapping[ s[dif]-'a' ] == -1)
            {
                for (i=k-1;i>=0;i--)
                {
                    if (!mapped[i] && i < b[dif] - 'a')
                    {
                        done = true;
                        mapped[i] = true;
                        mapping[ s[dif]-'a' ] = i;
                        break;
                    }
                }
            }
            else
            {
                done = true;
            }

            if (done)
            {
                if (largeTemplate(dif+1))
                {
                    printf("YES\n");
                    for (i=0;i<k;i++)
                    {
                        printf("%c",(char)(mapping[i]+'a'));
                    }
                    printf("\n");

                    continue;
                }
            }
        }

        printf("NO\n");
    }

    return 0;
}