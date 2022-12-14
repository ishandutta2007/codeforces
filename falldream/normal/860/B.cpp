#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define ull unsigned long long
#define MN 70000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char st[MN+5][12];
ull ha[20],pw[20];
map<ull,int> mp[11];
int n;

int Solve(int x)
{
    //cout<<"Solve"<<x<<endl;
    for(int i=1;i+x-1<=9;++i)
    {
        ull Ha=ha[i+x-1]-ha[i-1]*pw[x];
        if(!mp[x][Ha]) return i;
    }
    return -1;
}

int main()
{
    n=read();pw[0]=1;
    srand((long long)new char);
    int seed=rand()%20000+10000;
    for(int i=1;i<=20;++i) pw[i]=pw[i-1]*seed;
    for(int i=1;i<=n;++i)
    {
        scanf("%s",st[i]+1);
        for(int j=1;j<=9;++j) ha[j]=ha[j-1]*seed+st[i][j];
        for(int ii=1;ii<=9;++ii)
            for(int j=ii;j<=9;++j)
                mp[j-ii+1][ha[j]-ha[ii-1]*pw[j-ii+1]]++;
    }
    for(int i=1;i<=n;++i)
    {
        int l=1,r=9,mid,res=9,t;
        for(int j=1;j<=9;++j) ha[j]=ha[j-1]*seed+st[i][j];
        for(int ii=1;ii<=9;++ii)
            for(int j=ii;j<=9;++j)
                mp[j-ii+1][ha[j]-ha[ii-1]*pw[j-ii+1]]--;
        while(l<=r)
        {
            mid=l+r>>1;
            if((t=Solve(mid))!=-1) res=mid,r=mid-1;
            else l=mid+1;
        }
        t=Solve(res);
        for(int j=0;j<res;++j) printf("%c",st[i][t+j]);
        for(int ii=1;ii<=9;++ii)
            for(int j=ii;j<=9;++j)
                mp[j-ii+1][ha[j]-ha[ii-1]*pw[j-ii+1]]++;
       // cout<<t<<" "<<res<<endl;
        cout<<endl;
    }
    return 0;
}