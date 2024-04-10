//source:
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
int x,vis[111][111];
/*void mark(int x,int y)
{
    vis[x][y]++;
    vis[x-1][y]++;
    vis[x+1][y]++;
    vis[x][y-1]++;
    vis[x][y+1]++;
}*/
bool dfs(int size,int rest)
{
//  cout<<"dfs:"<<size<<" "<<rest<<endl;
    if(rest&1)
    {
        if(size%2==0)return false;
        vis[size/2+1][size/2+1]=1;
        return dfs(size,rest-1);
    }
    else
    {
        if(rest>=4)
        {
            int tmp=rest;
            for(int i=1;i<size/2;i++)
            {
                for(int j=(i+1)%2+1;j<size/2;j+=2)
                {
                    if(vis[i][j])continue;
                    if(rest-4<0)break;
                    rest-=4;
                    vis[i][j]=1;
                }
            }
            if(size&1)
            {
                for(int i=(size/2+1)%2+1;i<=size/2;i+=2)
                {
                    if(vis[i][size/2])continue;
                    if(rest-4<0)break;
                    rest-=4;
                    vis[i][size/2]=1;
                }
                for(int i=(size/2+1)%2+1;i<size/2;i+=2)
                {
                    if(vis[size/2][i])continue;
                    if(rest-4<0)break;
                    rest-=4;
                    vis[size/2][i]=1;
                }
            }
            if(rest==0)return true;
        }
        if(rest!=0)
        {
            if(size%2==0)return false;
            for(int i=1;i<size/2+1;i++)
            {
                if(rest-2<0)break;
                if(vis[i][size/2]||vis[i+1][size/2+1])continue;
                rest-=2;
                vis[i][size/2+1]=1;
                i++;
            }
            for(int i=1;i<size/2+1;i++)
            {
                if(rest-2<0)break;
                if(vis[size/2][i]||vis[size/2+1][i+1])continue;
                rest-=2;
                vis[size/2+1][i]=1;
                i++;
            }
            return rest==0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>x;
    for(int i=1;i<=100;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i,x))
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}