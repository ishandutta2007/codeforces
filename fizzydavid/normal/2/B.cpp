//source:codeforces 2B
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
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
struct data
{
    int cnt2,cnt5,dp2,dp5;
    bool path2,path5;
    bool vis2,vis5;
}a[1011][1011];
int n;
void add(int x,int y,int v)
{
    int t=v;
    while(t>0)
    {
        if(t%2==0)t=t/2;else break;
        a[x][y].cnt2++;
    }
    t=v;
    while(t>0)
    {
        if(t%5==0)t=t/5;else break;
        a[x][y].cnt5++;
    }
}
int dp2(int x,int y)
{
    if(a[x][y].vis2)return a[x][y].dp2;
    a[x][y].dp2=a[x][y].cnt2;
    int t=a[x][y].dp2;
    if(x==1&&y==1)return a[x][y].dp2;
    a[x][y].vis2=1;
    int t1=INF,t2=INF;
    if(x>1)t1=dp2(x-1,y);
    if(y>1)t2=dp2(x,y-1);
    if(t1<t2)
    {
        a[x][y].path2=1,a[x][y].dp2+=t1;
    }
    else 
    {
        a[x][y].dp2+=t2,a[x][y].path2=0;
    }
//  cout<<"dp2:"<<x<<","<<y<<" "<<t<<" "<<a[x][y].dp2<<endl;
    return a[x][y].dp2;
}
int dp5(int x,int y)
{
    if(a[x][y].vis5)return a[x][y].dp5;
    a[x][y].dp5=a[x][y].cnt5;
    if(x==1&&y==1)return a[x][y].dp5;
    a[x][y].vis5=1;
    int t1=INF,t2=INF;
    if(x>1)t1=dp5(x-1,y);
    if(y>1)t2=dp5(x,y-1);
    if(t1<t2)
    {
        a[x][y].path5=1,a[x][y].dp5+=t1;
    }
    else
    {
        a[x][y].dp5+=t2,a[x][y].path5=0;
    }
    return a[x][y].dp5;
}
void go2(int x,int y)
{
    if(x==1&&y==1)return;
    else
    {
        if(a[x][y].path2)
        {
            go2(x-1,y);cout<<"D";
        }
        else
        {
            go2(x,y-1);cout<<"R";
        }
    }
}
void go5(int x,int y)
{
//  cout<<"go5:"<<x<<","<<y<<endl;
    if(x==1&&y==1)return;
    else
    {
        if(a[x][y].path5)
        {   
            go5(x-1,y);cout<<"D";
        }
        else
        {
            go5(x,y-1);cout<<"R";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    bool has0=0;int zx=-1,zy=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int v;
            cin>>v;
            if(v==0)has0=1,v=10,zx=i,zy=j;
            add(i,j,v);
        }
    }
    int ans1=dp2(n,n),ans2=dp5(n,n);
/*  
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"data:"<<i<<","<<j<<":"<<endl;
            cout<<"cnt2:"<<a[i][j].cnt2<<" cnt5:"<<a[i][j].cnt5<<endl;
            cout<<"dp2:"<<a[i][j].dp2<<" dp5:"<<a[i][j].dp5<<endl;
            cout<<"path2:"<<a[i][j].path2<<" path5:"<<a[i][j].path5<<endl;
            cout<<endl;
        }
    }
    system("pause");
*/  if(has0&&min(ans1,ans2)>=1)
    {
        cout<<1<<endl;
        for(int i=1;i<zx;i++)cout<<"D";
        for(int i=1;i<n;i++)cout<<"R";
        for(int j=zx;j<n;j++)cout<<"D";
    }
    else if(ans1<ans2)
    {
        cout<<ans1<<endl;
        go2(n,n);
    }
    else
    {
        cout<<ans2<<endl;
        go5(n,n);
    }
    return 0;
}