#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MAXN = 300*1000+10;
int n,r;
bool o[MAXN];
vector<int>V[MAXN];
int s[MAXN];
int ans;

void dfs(int x,int p) {
    for(auto nbh:V[x]) {
        if(o[x]==0) {
            r-=(s[x]-s[nbh]);
        }
        dfs(nbh,x);
        if(o[x]==0) {
            r+=(s[x]-s[nbh]);
        }
    }
    //cout<<x<<" "<<r<<"\n";
    if(V[x].size()==0)
    ans=max(ans,r);
}

void dfs2(int x) {
    for(auto nbh:V[x]) dfs2(nbh);
    if(V[x].size()==0) {
        s[x]=1;
        r++;
    }
    else {
        if(o[x]==0)
            for(auto nbh:V[x]) s[x]+=s[nbh];
        else {
            s[x] = 1000*1000*1000;
            for(auto nbh:V[x]) s[x]=min(s[x],s[nbh]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) cin>>o[i];
    for(int i=2; i<=n;i++) {
        int a;
        cin>>a;
        V[a].PB(i);
    }
    dfs2(1);
    //for(int i=1; i<=n;i++) cout<<s[i]<<" ";
    //cout<<"\n";
    dfs(1,0);
    cout<<ans;
}