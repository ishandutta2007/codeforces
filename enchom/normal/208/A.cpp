#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

char song[501];
char words[501][501];
Int wL[501];
Int word;
Int sL=0;

int main()
{
    string k;
    Int i,j;
    
    cin>>k;
    
    for (i=0;i<k.length();i++)
    song[i+1]=k[i];
    
    sL=k.length();
    
    for (i=1;i<=500;i++)
    {
        wL[i]=0;
    }
    word=1;
    i=1;
    
    
    while(i<=sL)
    {
        if (sL-i<2)
        {
            wL[word]++;
            words[word][wL[word]]=song[i];
        }
        else
        {
            if (song[i]=='W' && song[i+1]=='U' && song[i+2]=='B')
            {
                i=i+3;
                if (wL[word]>0)
                {
                    word++;
                }
                continue;
            }
            else
            {
                wL[word]++;
                words[word][wL[word]]=song[i];
            }
        }
        i++;
    }
    if (words[wL[word]]==0)
    word--;
    
    for (i=1;i<=word;i++)
    {
        for (j=1;j<=wL[i];j++)
        {
            printf("%c",words[i][j]);
        }
        if (i==word)
        printf("\n");
        else
        printf(" ");
    }
    return 0;
}