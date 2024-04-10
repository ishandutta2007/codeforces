#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int Nr,A,n,i,j,cr[1000009],ap[1000009];
vector < pair < int , int > > v;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=2;i*i<=n;i++)
if(cr[i]==0)
{
    for(j=i*i;j<=n;j+=i)
        cr[j]=1;
}
for(i=3;i<=n/2;i++)
    if(cr[i]==0)
    {
        Nr=0;
        for(j=i;j<=n;j+=i)
            if(ap[j]==0) Nr++;
        if(Nr&1)
        {
            A=i;
            ap[i]=1;
            for(j=i*3;j<=n;j+=i)
                if(ap[j]==0)
                {
                    ap[j]=1;
                    if(A!=0) v.push_back(make_pair(A,j)),A=0;
                    else A=j;
                }
        }
        else
        {
            A=0;
            for(j=i;j<=n;j+=i)
                if(ap[j]==0)
                {
                    ap[j]=1;
                    if(A!=0) v.push_back(make_pair(A,j)),A=0;
                    else A=j;
                }
        }
    }
A=0;
for(j=2;j<=n;j+=2)
    if(ap[j]==0)
    {
        ap[j]=1;
        if(A!=0) v.push_back(make_pair(A,j)),A=0;
        else A=j;
    }
printf("%d\n",v.size());
for(i=0;i<v.size();i++)
    printf("%d %d\n",v[i].first,v[i].second);
return 0;
}