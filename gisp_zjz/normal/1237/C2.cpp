#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=3e5+7;
struct node{
    int x,y,z,id;
};
typedef vector<node> vi;
typedef vector<int> Vi;
typedef vector<pi> vii;
vector <pi> h[maxn];
vector <pi> ans;
map <int,vi> f;
map <int,vii> g;
Vi s,t;
int n;
void solve(vi a){
    t.clear();
    for (int i=0;i<a.size();i++) g[a[i].y].pb((pi){a[i].z,a[i].id});
    for (auto q:g){
        vii tmp=q.S;
        sort(tmp.begin(),tmp.end());
        int m=tmp.size();
        for (int i=m%2;i<m;i+=2) ans.pb((pi){tmp[i].S,tmp[i+1].S});
        if (m%2) t.pb(tmp[0].S);
    }
    int m=t.size();
    for (int i=m%2;i<m;i+=2) ans.pb((pi){t[i],t[i+1]});
    if (m%2) s.pb(t[0]);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        node tmp;
        tmp.id=i;
        scanf("%d%d%d",&tmp.x,&tmp.y,&tmp.z);
        f[tmp.x].pb(tmp);
    }
    for (auto p:f){
        g.clear();
        solve(p.S);
    }
    for (int i=0;i<s.size();i+=2) ans.pb((pi){s[i],s[i+1]});
    for (auto x:ans) cout << x.F << ' ' << x.S << endl;
    return 0;
}