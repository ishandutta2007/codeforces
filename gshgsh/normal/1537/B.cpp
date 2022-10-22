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
#define abs(x) ((x)>0?(x):-(x))
int T,N,M,a,b;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>N>>M>>a>>b;vector<Pair>s;s.pb({a,b});if(a!=1||b!=1)s.pb({1,1});if(a!=1||b!=M)s.pb({1,M});if(a!=N||b!=1)s.pb({N,1});if(a!=N||b!=M)s.pb({N,M});
        int K=s.size();vector<vector<ll> >dis(K);For(i,0,K-1)dis[i].resize(K);For(i,0,K-1)For(j,0,K-1)dis[i][j]=abs(s[i].F-s[j].F)+abs(s[i].S-s[j].S);
        For(k,0,K-1)For(i,0,K-1)For(j,0,K-1)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        ll ans=0,x=0,y=0;For(i,1,K-1)For(j,i+1,K-1)if(dis[0][i]+dis[i][j]+dis[j][0]>ans)ans=dis[0][i]+dis[i][j]+dis[j][0],x=i,y=j;
        cout<<s[x].F<<' '<<s[x].S<<' '<<s[y].F<<' '<<s[y].S<<endl;
    }
    return 0;
}