#include<bits/stdc++.h>
#define maxn 234000
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
int n,m,k,a[maxn],r[10],ans;
set <int> s;

void dfs(int x,int y,int z)
{
    if (s.find(x)!=s.end()) ans=max(ans,z);
    if (y){
        dfs(x,y-1,z);
        dfs(x*10+r[y-1],y-1,z+1);
    }
}

int main()
{
    for (int i=1;i<=45000;i++) s.insert(i*i);
    scanf("%d",&n); ans=0;
    m=n; k=0;
    while (m){
        r[k++]=m%10;
        m/=10;
    }
    for (int i=k-1;i>=0;i--)
    {
        if (!r[i]) continue;
        dfs(r[i],i,1);
    }
    if (ans) cout << k-ans << endl; else cout << -1 << endl;
    return 0;
}