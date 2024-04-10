#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

char inp[100001];
int seq1[1000001];
int seq2[1000001];
int L1,L2;

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int main()
{
    memset(seq1,0,sizeof(seq1));
    memset(seq2,0,sizeof(seq2));

    int i,j;
    int cur=0;

    scanf("%s",inp+1);
    L1=strlen(inp+1);
    for (i=1;i<=L1;i++)
    {
        seq1[i]=inp[i]-'0';
    }

    scanf("%s",inp+1);
    L2=strlen(inp+1);
    for (i=1;i<=L2;i++)
    {
        seq2[i]=inp[i]-'0';
    }

    reverse(seq1+1,seq1+1+L1);
    reverse(seq2+1,seq2+1+L2);

    for (i=3*L1;i>=3;i--)
    {
        if (seq1[i-2]>0 && seq1[i-1]>0)
        {
            seq1[i]++;

            seq1[i-1]--;
            seq1[i-2]--;

            cur=i;

            while(seq1[cur]>0 && seq1[cur+1]>0)
            {
                seq1[cur]--;
                seq1[cur+1]--;
                seq1[cur+2]++;
                cur+=2;
            }
        }
    }

    for (i=3*L2;i>=3;i--)
    {
        if (seq2[i-2]>0 && seq2[i-1]>0)
        {
            seq2[i-2]--;
            seq2[i-1]--;

            seq2[i]++;

            cur=i;

            while(seq2[cur]>0 && seq2[cur+1]>0)
            {
                seq2[cur]--;
                seq2[cur+1]--;
                seq2[cur+2]++;
                cur+=2;
            }
        }
    }

    for (i=MAX(3*L1,3*L2);i>=1;i--)
    {
        if (seq1[i]>seq2[i])
        {
            printf(">\n");
            return 0;
        }
        else if (seq1[i]<seq2[i])
        {
            printf("<\n");
            return 0;
        }
    }

    printf("=\n");

    return 0;
}