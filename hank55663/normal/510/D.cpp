#include<stdio.h>
#include<math.h>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
struct card{
int length;
int cost;
};
bool operator<(const card &a,const card &b)
{
    if(a.cost!=b.cost)
    return a.cost<b.cost;
    return a.length<b.length;
}
int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
card c[400];
main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i].length);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i].cost);
    map<int,int> m;
    map<int,int> ::iterator it;
    for(int i=0;i<n;i++)
    {
        if(m[c[i].length]==0)
            m[c[i].length]=c[i].cost;
        else
            m[c[i].length]=min(c[i].cost,m[c[i].length]);
        for(it=m.begin();it!=m.end();it++)
        {
            int x=gcd(c[i].length,it->first);
            if(m[x]==0)
                m[x]=c[i].cost+it->second;
            else
                m[x]=min(m[x],c[i].cost+it->second);
        }
    }
    if(m[1]==0)
        m[1]=-1;
    printf("%d",m[1]);
    return 0;
}