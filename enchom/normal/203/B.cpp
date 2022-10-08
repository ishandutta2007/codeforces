#include <iostream>
#include <stdio.h>
using namespace std;

int blacksquares[1025][1025];
int OFFSET=5;

int main()
{
    int i,j;
    int n,k;
    int a,b;
    bool answer=false;
    for (i=0;i<=1024;i++)
    {
        for (j=0;j<=1024;j++)
        {
            blacksquares[i][j]=0;
        }
    }
    cin>>n>>k;
    for (i=1;i<=k;i++)
    {
        scanf("%d %d",&a,&b);
        
        if (!answer)
        {
            a=a+OFFSET;
            b=b+OFFSET;
        
            blacksquares[a-2][b-2]++;
            if (blacksquares[a-2][b-2]==9)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a-2][b-1]++;
            if (blacksquares[a-2][b-1]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a-2][b]++;
            if (blacksquares[a-2][b]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a-1][b-2]++;
            if (blacksquares[a-1][b-2]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a-1][b-1]++;
            if (blacksquares[a-1][b-1]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a-1][b]++;
            if (blacksquares[a-1][b]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a][b-2]++;
            if (blacksquares[a][b-2]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a][b-1]++;
            if (blacksquares[a][b-1]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        
            blacksquares[a][b]++;
            if (blacksquares[a][b]==9 && !answer)
            {
                cout<<i<<endl;
                answer=true;
            }
        }
        
    }
    if (!answer)
    cout<<-1<<endl;
    return 0;
}