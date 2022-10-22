#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define pb push_back
#define MAXN 501
int N,K,dep[MAXN],pre[MAXN];vector<int>ans;
void solve(int &x,set<int>&now,int v)
{
    int cnt=now.size()+K-v>>1;
    vector<int>a;for(auto i:now)if(cnt)a.pb(i),cnt--;
    For(i,1,N)if(a.size()<K&&now.find(i)==now.end())a.pb(i);
    cout<<"? ";for(auto i:a)cout<<i<<' ';cout<<endl;int y;cin>>y;x^=y;
    for(auto i:a)if(now.find(i)==now.end())now.insert(i);else now.erase(i);
}
int main()
{
    cin>>N>>K;queue<int>q;q.push(0);For(i,1,N)dep[i]=N+1;
    while(!q.empty()){int u=q.front();q.pop();int x=u+K,y=0;while(x+y>N)x-=2,y++;while(x>=u+K-min(u,K)*2)dep[x]==N+1?dep[x]=dep[u]+1,pre[x]=u,q.push(x),0:0,x-=2;}
    if(dep[N]==N+1){cout<<-1<<endl;return 0;}int u=N;while(u)ans.pb(u),u=pre[u];reverse(ans.begin(),ans.end());
    int now=0,x=0;set<int>a;for(auto i:ans)solve(x,a,i);cout<<"! "<<x<<endl;return 0;
}