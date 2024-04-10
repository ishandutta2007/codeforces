#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef long long Int;

struct movie
{
    string name;
    Int actors;
    Int aL;
    Int actor[101];
    Int dmin,dmax;
};

movie movies[101];
bool favorite[101];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    Int n,m,k;
    Int i,j;
    Int a;
    Int favorites;
    Int freespace;
    Int loseractors;
    bool flag;
    
    for (i=0;i<=100;i++)
    {
        favorite[i]=false;
    }
    
    scanf("%I64d %I64d",&m,&k);
    
    for (i=1;i<=k;i++)
    {
        scanf("%I64d",&a);
        
        favorite[a]=true;
    }
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        cin>>movies[i].name;
        scanf("%I64d",&movies[i].actors);
        
        movies[i].aL=0;
        
        for (j=1;j<=movies[i].actors;j++)
        {
            scanf("%I64d",&a);
            
            if (a!=0)
            {
                movies[i].aL++;
                movies[i].actor[ movies[i].aL ]=a;
            }
        }
        
        favorites=0;
        for (j=1;j<=movies[i].aL;j++)
        {
            if ( favorite[ movies[i].actor[j] ] )
            favorites++;
        }
        
        freespace=movies[i].actors-movies[i].aL;
        
        if (freespace>=k-favorites)
        {
            movies[i].dmax=k;
        }
        else
        {
            movies[i].dmax=favorites+freespace;
        }
        
        loseractors=movies[i].aL-favorites;
        
        freespace=freespace-(m-loseractors-k);
        
        if (freespace>0)
        {
            movies[i].dmin=favorites+freespace;
        }
        else
        {
            movies[i].dmin=favorites;
        }
    }
    
    for (i=1;i<=n;i++)
    {
        flag=true;
        for (j=1;j<=n;j++)
        {
            if (i==j)
            continue;
            
            if (movies[j].dmax>movies[i].dmin)
            {
                flag=false;
                break;
            }
        }
        
        if (flag)
        {
            printf("0\n");
            continue;
        }
        
        
        flag=false;
        for (j=1;j<=n;j++)
        {
            if (i==j)
            continue;
            
            if (movies[j].dmin>movies[i].dmax)
            {
                flag=true;
                break;
            }
        }
        
        if (flag)
        {
            printf("1\n");
            continue;
        }
        
        printf("2\n");
    }
    return 0;
}