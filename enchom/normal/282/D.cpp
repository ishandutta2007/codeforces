#include <iostream>
#include <stdio.h>
using namespace std;

int lose[301];
bool possible[301];

int main()
{
    int n;
    int a,b,c;
    int i,j;
    int badk;
    
    cin>>n;
    
    if (n==1)
    {
        cin>>a;
        if (a==0)
        cout<<"BitAryo"<<endl;
        else
        cout<<"BitLGM"<<endl;
    }
    else if (n==2)
    {
        ///Here is the dynamic i talked about
        lose[0]=0;
        
        for (i=1;i<=300;i++)
        {
            for (j=0;j<=300;j++)
            {
                possible[j]=true;
            }
            
            for (j=0;j<=i-1;j++)
            {
                ///looking at [ j,lose[j] ], eliminating such k that could lead here
                if (lose[j]==-1)
                {
                    continue;
                }
                
                badk=lose[j]+(i-j);
                ///[ i,badk ], if we substract (i-j) from both of them, we will get [ j,lose[j] ], therefor we eliminate badk to be our k
                if (badk<=300) ///careful to not get out of array bounds
                possible[badk]=false;
                
                ////////////////////
                
                ///[ i,lose[j] ], if we substract (i-j) from the first, we get [ j,lose[j] ], therefor lose[j] is another option we eliminate
                possible[lose[j]]=false;
            }
            
            lose[j]=-1; ///if the answer is higher than 300, then we don't need it
            for (j=0;j<=300;j++)
            {
                if (possible[j])
                {
                    lose[i]=j;
                    break;
                }
            }
        }
        
        cin>>a>>b;
        
        if (lose[a]==b)
        {
            cout<<"BitAryo"<<endl;
        }
        else
        {
            cout<<"BitLGM"<<endl;
        }
    }
    else
    {
        cin>>a>>b>>c;
        
        if ( (a^b^c)==0 )
        {
            cout<<"BitAryo"<<endl;
        }
        else
        {
            cout<<"BitLGM"<<endl;
        }
    }
    
    return 0;
}