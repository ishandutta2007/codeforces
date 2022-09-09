// by Imagine_I https://codeforces.com/contest/1463/submission/101574060
#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vi  = vector<int>;
using pii = pair<int,int>;
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=int(a);i<=(int)(b);i++)
#define per(i,a,b) for(int i=int(a);i>=(int)(b);i--)
const int mod  = 1e9+7;
const int maxn = 3e5+10;
const int inf  = 0x3f3f3f3f;
int pre[maxn];
int fa[maxn];
int Find(int x) {
    if(x==fa[x]) return x;
    else return fa[x]=Find(fa[x]);
}
void Union(int a,int b) {
    fa[Find(b)]=Find(a);
}
vi g[maxn];
bool hasl[maxn],hasr[maxn];
int valr[maxn],pos[maxn],id[maxn];
int du[maxn];
vector<int> a[maxn];
int n,k;
int main() {
#ifndef WA_DEBUG
    ios::sync_with_stdio(false);cin.tie(nullptr);
#endif
    cin>>n>>k;
    rep(i,1,n) {
        cin>>pre[i];
        fa[i]=i;
    }
    rep(i,1,k) {
        int l,r;
        cin>>l>>r;
        valr[l]=r;
        if(hasr[l]||hasl[r]||Find(l)==Find(r)) {
            cout<<0<<'\n';
            return 0;
        }
        Union(l,r);
        hasl[r]=true;
        hasr[l]=true;
    }
    int cnt=0;
    rep(i,1,n) {
        if(hasl[i]) continue;
        cnt++;
        int now=i;
        while(now!=0) {
            id[now]=cnt;
            a[cnt].pb(now);
            now=valr[now]; 
        }
    }
    rep(i,1,n) {
        int p=pre[i];
        if(p==0) continue;
        int idi=id[i],idp=id[p];
        if(idi==idp) continue;
        g[idp].pb(idi);
        du[idi]++;
    }
    vi ans;
    queue<int> q;
    rep(i,1,cnt) {
        if(du[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int now=q.front();q.pop();
        for(int x:a[now]) {
            pos[x]=ans.size();
            ans.pb(x);
        }
        for(int x:g[now]) {
            du[x]--;
            if(du[x]==0) q.push(x);
        }
    }
    bool f = ((int)ans.size() == n);
    rep(i,1,n) {
        if(pre[i]==0) continue;
        if(pos[pre[i]]>pos[i]) {
            f=false;
            break;
        }
    }
    if(f) {
        for(int x:ans) cout<<x<<' ';
        cout<<'\n';
    }
    else cout<<0<<'\n';
    return 0;
}