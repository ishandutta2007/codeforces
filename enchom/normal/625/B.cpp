#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char text[100111];
int n;
char word[33];
int m;

int main()
{
    int i,j;
    bool match;
    int ans=0;

    scanf("%s",text+1);
    n=strlen(text+1);
    scanf("%s",word+1);
    m=strlen(word+1);

    for (i=1;i<=n-m+1;i++)
    {
        match=true;
        for (j=i;j<=i+m-1;j++)
        {
            if (word[j-i+1]!=text[j])
            {
                match=false;
                break;
            }
        }

        if (match)
        {
            text[i+m-1]='#';
            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}