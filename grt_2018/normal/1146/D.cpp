#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
const int INF = 1000*1000*1000;
int m,a,b,t;
int visited[nax];
LL ans;

void dfs(int x,int ma) {
    visited[x]=ma;
    if(x-b>=0&&visited[x-b]==INF) {
        dfs(x-b,ma);
    }
    if(x+a<=t&&visited[x+a]==INF) {
        dfs(x+a,max(ma,x+a));
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>a>>b;
    t = min(m,a+b);
    for(int i=0; i<=t;i++) {
        visited[i]=INF;
    }
    dfs(0,0);
    for(int i=0; i<=t;i++) {
        ans+=max(0,m - visited[i]+1);
    }
    int g = __gcd(a,b);
    int x = ((a+b)/g)+1;
    int y = (m/g);
    //cout<<ans<<" "<<x<<" "<<y<<"\n";
    if(x<=y) {
        ans+=(LL)(m+1)*((y-x)+1);
        ans-=(LL)x*g*(y-x+1);
        ans-=(LL)g*((LL)(y-x)*(y-x+1))/2;
    }
    cout<<ans;
}