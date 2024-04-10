#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef unsigned long long ullong;
typedef long long llong;

llong B1 = 127LL;
ullong B2 = 37ULL;
llong MOD = 1000000009LL;

llong B1Pows[1000111];
ullong B2Pows[1000111];

struct hashPair
{
    pair<llong, ullong> H1 = make_pair(0, 0), H2 = make_pair(0, 0);
    int len = 0;

    hashPair(): H1(make_pair(0, 0)), H2(make_pair(0, 0)), len(0) {}

    bool pali()
    {
        return H1 == H2;
    }

    void addChar(char ch)
    {
        llong v = (llong)ch;

        H1.first *= B1;
        H1.first += v;
        H1.first %= MOD;

        H1.second *= B2;
        H1.second += (ullong)v;

        //

        H2.first += B1Pows[len] * v;
        H2.first %= MOD;

        H2.second += B2Pows[len] * (ullong)v;

        len++;
    }
};

int t;
char s[1000111];
int n;

char res[1000111];
int rL;

int main()
{
    int test;
    int i,j;

    B1Pows[0] = 1LL;
    B2Pows[0] = 1ULL;
    for (i=1;i<=1000000;i++)
    {
        B1Pows[i] = (B1Pows[i-1] * B1) % MOD;
        B2Pows[i] = B2Pows[i-1] * B2;
    }

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%s",s+1);
        n = strlen(s+1);

        int L = 1, R = n;

        while(L < R)
        {
            if (s[L] == s[R])
            {
                L++;
                R--;
            }
            else
                break;
        }

        hashPair lft;
        int bestLeft = 0;
        for (i=L;i<=R;i++)
        {
            lft.addChar(s[i]);
            if (lft.pali())
            {
                bestLeft = i - L + 1;
            }
        }

        hashPair rt;
        int bestRight = 0;
        for (i=R;i>=L;i--)
        {
            rt.addChar(s[i]);
            if (rt.pali())
            {
                bestRight = R - i + 1;
            }
        }

        rL = 0;
        for (i=1;i<L;i++)
        {
            res[rL] = s[i];
            rL++;
        }

        if (bestLeft >= bestRight)
        {
            for (i=L;i<=L+bestLeft-1;i++)
            {
                res[rL] = s[i];
                rL++;
            }
        }
        else
        {
            for (i=R-bestRight+1;i<=R;i++)
            {
                res[rL] = s[i];
                rL++;
            }
        }

        for (i=R+1;i<=n;i++)
        {
            res[rL] = s[i];
            rL++;
        }

        res[rL] = 0;

        printf("%s\n",res);
    }

    return 0;
}