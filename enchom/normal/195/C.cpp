#include <iostream>
#include <stdio.h>
using namespace std;

int blocks=0;
int throwed=-1;
char throwexception[23];
char answer[25];
int aL=0;
char Exception[23];
int teL=0,exL=0;

bool Same(char arr1[],int L1,char arr2[],int L2)
{
    if (L1!=L2)
    return false;
    else
    {
        int i;
        for (i=1;i<=L1;i++)
        {
            if (arr1[i]!=arr2[i])
            return false;
        }
        return true;
    }
}

int main()
{
    int n;
    char line[52],L=0;
    char input;
    int start,end;
    int i,j;
    bool finished=false;
    int shit;
    cin>>n;
    scanf("%c",&input);
    for (i=1;i<=n;i++)
    {
        L=0;
        exL=0;
        shit=1;
        while(1)
        {
            scanf("%c",&input);
            
            if (input=='"')
            {
                if (shit==1)
                shit=0;
                else
                shit=1;
            }
            
            if ( (int)input==10 )
            break;
            if ( input!=' ' || shit==0 )
            {
                L++;
                line[L]=input;
            }
        }
        if (finished)
        continue;
        
        if (L==0)
        continue;
        
        if (line[1]=='t' && line[2]=='r' && line[3]=='y')
        {
            blocks++;
            continue;
        }
        if (line[1]=='t' && line[2]=='h' && line[3]=='r' && line[4]=='o' && line[5]=='w')
        {
            throwed=blocks;
            for (j=1;j<=L;j++)
            {
                if (line[j]=='(')
                {
                    start=j+1;
                }
                if (line[j]==')')
                {
                    end=j-1;
                }
            }
            for (j=start;j<=end;j++)
            {
                teL++;
                throwexception[teL]=line[j];
            }
            continue;
        }
        if (line[1]=='c' && line[2]=='a' && line[3]=='t' && line[4]=='c' && line[5]=='h')
        {
            if (throwed==-1)
            {
                blocks--;
                continue;
            }
            else
            {
                if (throwed==blocks)
                {
                    start=-1;
                    end=-1;
                    for (j=1;j<=L;j++)
                    {
                        if (line[j]=='(' && start==-1)
                        start=j+1;
                        if (line[j]==',' && end==-1)
                        end=j-1;
                    }
                    for (j=start;j<=end;j++)
                    {
                        exL++;
                        Exception[exL]=line[j];
                    }
                    
                    if (Same(Exception,exL,throwexception,teL))
                    {
                        start=-1;
                        for (j=1;j<=L;j++)
                        {
                            if (line[j]=='"' && start==-1)
                            start=j+1;
                            
                            if (line[j]=='"')
                            end=j-1;
                        }
                        for (j=start;j<=end;j++)
                        {
                            aL++;
                            answer[aL]=line[j];
                        }
                        finished=true;
                    }
                    else
                    {
                        throwed--;
                        blocks--;
                    }
                }
                else
                {
                    blocks--;
                    continue;
                }
            }
        }
    }
    if (!finished)
    cout<<"Unhandled Exception"<<endl;
    else
    {
        for (i=1;i<=aL;i++)
        cout<<answer[i];
        cout<<endl;
    }
    return 0;
}