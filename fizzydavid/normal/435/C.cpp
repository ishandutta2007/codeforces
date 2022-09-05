#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair 
#define P system("pause")
vector<pair<int,char> >a[200111];
int n,p[100111];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    int tmp=0,dir=1,x=0,y=0,mx=100000,mn=100000;
    for(int i=1;i<=n;i++)
    {
//      cout<<"i="<<i<<" dir="<<dir<<endl;
        for(int loc=x+p[i];x<loc;x++,y+=dir)
        {
            char c;
//          cout<<"x="<<x<<" y="<<y<<endl;
            if(dir==1)c='/';
            else c=92;
            a[y+100000].push_back(make_pair(x,c));
            mx=max(mx,y+100000);mn=min(mn,y+100000);
        }y-=dir;
        dir*=-1;
//      cout<<i<<"completed"<<endl;P;
    }
    for(int i=mx;i>=mn;i--)
    {
        for(int j=0,t=0;j<x;j++)
        {
            if(j==a[i][t].ff)
            {
                printf("%c",a[i][t].ss);
                if(t<a[i].size()-1)t++;
            }
            else
            {
                printf(" ");
            }
        }
        puts("");
    }
//  system("pause");
    return 0;
}