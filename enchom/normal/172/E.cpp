#include <iostream>
#include <stdio.h>
using namespace std;

struct tag
{
    bool open;
    char name[11];
    int nameL;
};

tag tags[2000001];
int tL=0;
int places[100001];
int uk;

bool Same(char arr1[],int L1,char arr2[],int L2)
{
    int i;
    if (L1!=L2)
    {
        return false;
    }
    for (i=1;i<=L1;i++)
    {
        if (arr1[i]!=arr2[i])
        return false;
    }
    return true;
}

int main()
{
    int i,j;
    char atag[20],input;
    char question[201][11];
    int questions=0;
    int qL[201];
    int currtags=0;
    int atL=0;
    int m;
    int ways=0;
    
    for (i=0;i<=200;i++)
    qL[i]=0;
    
    while (1)
    {
        atL++;
        scanf("%c",&atag[atL]);
        if (atag[atL]==10)
        {
            atL--;
            break;
        }
        
        if (atag[atL]=='>')
        {
            tL++;
            if (atag[2]=='/')
            {
                tags[tL].open=false;
                tags[tL].nameL=atL-3;
                for (i=3;i<=atL-1;i++)
                {
                    tags[tL].name[i-2]=atag[i];
                }
                atL=0;
                continue;
            }
            else if (atag[atL-1]!='/')
            {
                tags[tL].open=true;
                tags[tL].nameL=atL-2;
                for (i=2;i<=atL-1;i++)
                {
                    tags[tL].name[i-1]=atag[i];
                }
                atL=0;
                continue;
            }
            else
            {
                tags[tL].open=true;
                tags[tL].nameL=atL-3;
                for (i=2;i<=atL-2;i++)
                {
                    tags[tL].name[i-1]=atag[i];
                }
                
                tL++;
                tags[tL].open=false;
                tags[tL].nameL=atL-3;
                for (i=2;i<=atL-2;i++)
                {
                    tags[tL].name[i-1]=atag[i];
                }
                atL=0;
                continue;
            }
        }
    }
    
    cin>>m;
    scanf("%c",&input);
    for (i=1;i<=m;i++)
    {
        for (j=0;j<=200;j++)
        qL[j]=0;
        
        ways=0;
        questions=1;
        while(1)
        {
            scanf("%c",&input);
            if (input==' ')
            {
                questions++;
                continue;
            }
            if (input==10)
            break;
            
            qL[questions]++;
            question[ questions ][ qL[questions] ]=input;
        }
        uk=1;
        places[0]=-1;
        for (j=1;j<=tL;j++)
        {
            if (tags[j].open)
            {
                currtags++;
                if ( Same( question[uk],qL[uk],tags[j].name,tags[j].nameL ) )
                {
                    if (uk==questions)
                    {
                        ways++;
                    }
                    else
                    {
                        places[uk]=currtags;
                        uk++;
                    }
                }
                
            }
            else
            {
                if (places[uk-1]==currtags)
                {
                    uk--;
                }
                currtags--;
            }
        }
        printf("%d\n",ways);
    }
    return 0;
}