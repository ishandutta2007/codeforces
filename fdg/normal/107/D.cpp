#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

char type[1001];
int crat[1001],mod=12345,m;
vector < vector <int> > state;
vector <int> v;
bool need[27];

void gen(int t)
{
    if (t==m)
    {
        state.push_back(v);
        return;
    }
    for(int i=0;i<crat[t];i++)
    {
        v.push_back(i);
        gen(t+1);
        v.pop_back();
    }
}

int g[125][125],nx[125][27],tot;

vector <int> rec(ll n)
{
    if (n==0)
    {
        vector <int> ret(tot,0);
        ret[0]=1;
        return ret;
    }
    vector <int> v=rec(n>>1),ret(tot,0);
    for(int i=0;i<v.size();i++)
        for(int j=0;j<v.size();j++)
            ret[g[i][j]]=(ret[g[i][j]]+1LL*v[i]*v[j])%mod;
    if (n&1)
    {
        vector <int> tmp(tot),ret1(tot);
        for(int j=0;j<26;j++)
            if (need[j]) tmp[nx[0][j]]++;
        for(int i=0;i<ret.size();i++)
            for(int j=0;j<tmp.size();j++)
                ret1[g[i][j]]=(ret1[g[i][j]]+1LL*ret[i]*tmp[j])%mod;
        return ret1;
    }
    return ret;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll n;
    scanf("%I64d%d\n",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%c %d\n",&type[i],&crat[i]);
        need[type[i]-'A']=true;
    }
    bool leaf[1001]={0};
    for(int i=0;i<m;i++)
    {
        if (!leaf[i])
            for(int j=i+1;j<m;j++)
                if (type[j]==type[i]&&crat[j]==crat[i]) leaf[j]=true;
    }
    if (m)
    {
        int size=1;
        for(int i=1;i<m;i++)
            if (!leaf[i])
            {
                type[size]=type[i];
                crat[size]=crat[i];
                size++;
            }
        m=size;
    }
    gen(0);
//  for(int i=0;i<state.size();i++)
//  {
//      for(int j=0;j<state[i].size();j++)
//          cout << state[i][j] << "    ";
//      cout << endl;
//  }
//  for(int i=0;i<state.size();i++)
//      f[state[i]]=i;
//  vector <int> nv(state[0].size(),0);
    int mn[1002];
    mn[m]=1;
    mn[m-1]=crat[m-1];
    for(int i=m-2;i>=0;i--)
        mn[i]=mn[i+1]*crat[i];
    for(int i=0;i<state.size();i++)
    {
        for(int j=0;j<state.size();j++)
        {
            int num=0;
            for(int t=0;t<m;t++)
                num+=((state[i][t]+state[j][t])%crat[t])*mn[t+1];
            g[i][j]=num;
//          cout << i << "  " << j << " " << num << endl;
        }
    }
    for(int i=0;i<state.size();i++)
    {
        for(int j=0;j<26;j++)
        {
            if (!need[j]) continue;
            int num=0;
            for(int t=0;t<m;t++)
                num+=((state[i][t]+(type[t]==('A'+j)))%crat[t])*mn[t+1];
            nx[i][j]=num;
//          cout << i << "  " << j << " " << num << endl;
        }
    }
    tot=state.size();
    vector <int> v=rec(n);
//  for(int i=0;i<v.size();i++)
//      cout << v[i] << "   ";
//  cout << endl;
    int ans=0;
    for(int i=0;i<state.size();i++)
    {
        bool ok[27]={0};
        for(int j=0;j<state[i].size();j++)
            if (state[i][j]==0) ok[type[j]-'A']=true;
        bool add=true;
        for(int j=0;j<26;j++)
            if (need[j]&&!ok[j]) add=false;
        if (add) ans=(ans+v[i])%mod;
    }
    cout << ans << endl;
    return 0;
}