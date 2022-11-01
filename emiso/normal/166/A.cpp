//EM NOME DE ALA
// alrogitmo SORTE INDO E SORTE VOLTANO
//FEITO POR ERMESSON E PROTEGIFO PELA POLISIA FEREDAL
// SE COPIA E CRIME GRAVE
//COP WRITE 2014 HERBERT RICHERS

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int,int> > par;

bool sortDOEMERSON(pair<int,int> oi,pair<int,int> xau)
{
     if(oi.first > xau.first) return 1;
     if(oi.first == xau.first) if(oi.second < xau.second) return 1;
     return 0;
}

int main()
{
    int n,k,a,b;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
            scanf("%d %d",&a,&b);
            par.push_back(make_pair(a,b));
    }
    sort(par.begin(),par.end(),sortDOEMERSON);
    pair<int,int> monark = par[k-1];
    while(par[k-1]==monark) k--;                  
    k++;
    int count=0;
    while(par[k-1]==monark)
    {
                           count++;
                           k++;
    }
    printf("%d\n",count);
    return 0;
}