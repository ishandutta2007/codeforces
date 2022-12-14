#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 2000000000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int f1[7005],f2[7005];
int n,k1,k2;
int s[7005],s2[7005],r[7005],r2[7005];
struct node{
    int x,k;
};
queue<node> q;
/*.*
int calc(int*s,int*f,int pos,int tot)
{
    bool yes=false,lose=true;
    for(int i=1;i<=tot;i++)
    {
        if(pos+s[i]>n+1) continue;
        int x=f[(pos+s[i]-1)%n+1];
        if(x!=1) lose=false;
        if(x==0) yes=true;
    }
    cout<<"calc"<<pos<<" "<<tot<<" "<<yes<<" "<<lose<<endl;
    if(yes)return 1;
    if(lose)return 0;
    return 2;
}
 */

int main()
{
    n=read();k1=read();
    f1[1]=f2[1]=2;
    for(int i=1;i<=k1;i++)
    {
        s[i]=read()%n;
    }
    k2=read();
    for(int j=1;j<=k2;j++)
    {
        s2[j]=read()%n;
    }
    for(int i=1;i<=n;i++)r[i]=k1,r2[i]=k2;r[1]=r2[1]=INF;
    q.push((node){1,1});q.push((node){1,2});
    while(!q.empty())
    {
        node x=q.front();q.pop();
        //cout<<x.x<<" "<<x.k<<endl;
        if(x.k==1)
        {
            for(int i=1;i<=k2;i++)
            {
                int np=(x.x+n-s2[i]-1)%n+1;
              //  cout<<x.x<<" "<<x.k<<" "<<f1[x.x]<<" "<<np<<" "<<endl;
                if(f2[np])continue;
                if(f1[x.x]==1)
                {
                    r2[np]--;
                    if(!r2[np])
                        f2[np]=3-f1[x.x],q.push((node){np,2});
                }
                else
                {
                    f2[np]=3-f1[x.x];
                    q.push((node){np,2});
                }
            }
        }
        else
        {
            for(int i=1;i<=k1;i++)
            {
                int np=(x.x+n-s[i]-1)%n+1;
              //  cout<<x.x<<" "<<x.k<<" "<<f2[x.x]<<" "<<np<<" "<<endl;
                if(f1[np])continue;
                if(f2[x.x]==1)
                {
                    r[np]--;
                    if(!r[np])
                        f1[np]=3-f2[x.x],q.push((node){np,1});
                }
                else
                {
                    f1[np]=3-f2[x.x];
                    q.push((node){np,1});
                }
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(f1[i]==1)cout<<"Win ";
        else if(f1[i]==2) cout<<"Lose ";
        else cout<<"Loop ";
    }
    puts("");
    for(int i=2;i<=n;i++)
    {
        if(f2[i]==1)cout<<"Win ";
        else if(f2[i]==2) cout<<"Lose ";
        else cout<<"Loop ";
    }
    return 0;
}