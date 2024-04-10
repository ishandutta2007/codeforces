#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
#include <ctime>
#include <set>
#include <cmath>

#define ll unsigned long long

using namespace std;

struct edge{
    edge(int a,int b,int c) : x(a), y(b), val(c) {};
    int x,y,val;
};

bool operator < (const edge & a,const edge & b)
{
    return a.val<b.val;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a,b,c;
    cin >> n;
    for(int i=0;i<=n;i++)
        cin >> m;
    vector <edge> v;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        v.push_back(edge(a,b,c));
    }
    sort(v.begin(),v.end());
    bool used[1003]={0};
    int ans=0;
    while(true)
    {
        bool fdg=false;
        for(int i=0;i<v.size();i++)
        {
            if (used[v[i].y]) continue;
            used[v[i].y]=true;
            ans+=v[i].val;
            fdg=true;
            break;
        }
        if (!fdg) break;
    }
    int norm=0;
    for(int i=1;i<=n;i++)
        norm+=used[i];
    if (norm==n-1) cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}