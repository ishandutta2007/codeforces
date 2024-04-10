#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>

#define H first 
#define I second 

using namespace std;

vector <pair<int,int> > t;
queue <pair<int,int> > op;

int main()
{
    int i,n,k,p,s=0,o=-1;
    float m;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
                     scanf("%d",&p);
                     s+=p;
                     t.push_back(make_pair(p,i));
    }
    
    sort(t.begin(),t.end());
    
    for(i=1;i<=k;i++)
    {
                                             //printf("%d %d %d\n\n",t[0].H,t[1].H,t[2].H);
               if(t[0].H == t[n-1].H || (s%n != 0 && t[0].H == s/n && t[n-1].H == (s/n)+1)) 
              {
                   o=i-1;
                   break;
              }
              if(t[0].H != t[n-1].H)
              {
                     op.push(make_pair(t[n-1].I,t[0].I));
                     t[0].H++;
                     t[n-1].H--;
              }
              if(t[1].H<t[0].H || t[n-2].H > t[n-1].H) sort(t.begin(),t.end());
    }
    if(o==-1) o = k;
    printf("%d %d\n",t[n-1].H - t[0].H , o);
    for(i=0;i<o;i++)
    {
                    printf("%d %d\n",op.front().first,op.front().second);
                    op.pop();
    }
    return 0;
}