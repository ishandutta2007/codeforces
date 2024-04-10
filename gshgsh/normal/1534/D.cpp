#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define Pair pair<int,int>
#define F first
#define S second
#define pb push_back
#define MAXN 2001
int N,M,dep[MAXN],dis[MAXN];vector<int>id[MAXN];vector<Pair>ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
    N=get();cout<<"? 1"<<endl;For(i,1,N)dep[i]=get(),id[dep[i]].pb(i),M=max(M,dep[i]);
    int cnt[2]={0,0};For(i,1,M)cnt[i&1]+=id[i].size();
    if(cnt[0]>cnt[1])
    {
        For(i,1,M+1>>1)for(auto j:id[i*2-1]){cout<<"? "<<j<<endl;For(k,1,N)dis[k]=get();For(k,1,N)if(dis[k]==1&&(dep[k]==dep[j]-1||dep[k]==dep[j]+1))ans.pb({j,k});}
        cout<<"!"<<endl;for(auto i:ans)cout<<i.F<<' '<<i.S<<endl;return 0;
    }
    for(auto i:id[1])ans.pb({1,i});For(i,1,M>>1)for(auto j:id[i*2]){cout<<"? "<<j<<endl;For(k,1,N)dis[k]=get();For(k,1,N)if(dis[k]==1&&(dep[k]==dep[j]-1||dep[k]==dep[j]+1))ans.pb({j,k});}
    cout<<"!"<<endl;for(auto i:ans)cout<<i.F<<' '<<i.S<<endl;return 0;
}