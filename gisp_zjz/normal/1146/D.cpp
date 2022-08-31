#include<bits/stdc++.h>
#define maxn 300050
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
bool vis[maxn];
int a,b,m,pre[maxn],sz[maxn];
ll ans,cc;
int ffind(int x){
    if (pre[x]==x) return x;
    pre[x]=ffind(pre[x]);
    return pre[x];
}
void dfs(int x,int len){
    vis[x]=1; ++cc;
    if (x>=b&&!vis[x-b]) dfs(x-b,len);
    if (x<=len-a&&!vis[x+a]) dfs(x+a,len);
}

int main(){
    cin >> m >> a >> b;
    for (int i=0;i<=a+b;i++) pre[i]=i,sz[i]=1;
    ans=cc=1; vis[0]=1;
    for (int i=1;i<a+b;i++){
        if (i>=a&&vis[i-a]) dfs(i,i);
        ans+=cc;
        if (i==m) {cout << ans << endl;return 0;}
    }
    int d=__gcd(a,b);
    ll x=(m+1-a-b)/d;
    ans+=((a+b)/d+1+((a+b)/d+x))*x*d/2;
    ll pos=a+b+x*d;
    for (;pos<=m;pos++) ans+=pos/d+1;
    cout << ans << endl;
}