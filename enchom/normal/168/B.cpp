#include <iostream>
#include <stdio.h>
using namespace std;

char input[1200001];
int inputL=0;
bool amplif[1200001];
int lines=0;
int line;

int main()
{
    char ch;
    int isamplify;
    int i;
    lines=1;
    isamplify=5;
    while(scanf("%c",&ch)==1)
    {
        inputL++;
        input[inputL]=ch;
        if (ch==10)
        {
            if (isamplify!=1)
            {
                amplif[lines]=false;
            }
            else
            amplif[lines]=true;
            isamplify=5;
            lines++;
        }
        else if (isamplify==5)
        {
            if (ch!=' ')
            {
                if (ch=='#')
                isamplify=1;
                else
                isamplify=2;
            }
        }
    }
    lines--;
    line=1;
    for (i=1;i<=inputL;i++)
    {
        if (input[i]==' ')
        {
            if (amplif[line])
            cout<<input[i];
        }
        else if (input[i]==10)
        {
            if (line==lines)
            {
                cout<<input[i];
                return 0;
            }
            else
            {
                if (amplif[line] || amplif[line+1])
                {
                    cout<<input[i];
                }
                line++;
            }
        }
        else
        {
            cout<<input[i];
        }
    }
    return 0;
}