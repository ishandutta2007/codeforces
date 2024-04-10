#include <bits/stdc++.h>

using namespace std;

#define ST first
#define ND second
#define PB push_back

typedef long long LL;
typedef pair<int,int>pi;

const int MAXQ = 3*100*1000+10;
int q,R;
LL res;
pair<pi,int> t[MAXQ];
vector<pi>T[(1<<20)];
int par[2*MAXQ],sx[2*MAXQ],sy[2*MAXQ];
vector<pi>E;

void update(int a,int b, pi p) {
    a+=R; b+=R;
    T[a].PB(p);
    if(a!=b) T[b].PB(p);
    while(a/2!=b/2) {
        if(a%2==0) T[a+1].PB(p);
        if(b%2==1) T[b-1].PB(p);
        a/=2;
        b/=2;
    }
}

int Fund(int x) {
    if(x==par[x]) return x;
    return Fund(par[x]);
}

void dfs(int v,int tmp) {
    LL pom = res;
    if(v>=2*R) return;
    for(auto it:T[v]) {
        int x = it.ST, y = it.ND+MAXQ;
        x = Fund(x); y = Fund(y);
        if(x==y) continue;
        if(sx[x]+sy[x]<sx[y]+sy[y]) swap(x,y);
        res -= (LL)sx[x]*sy[x] + (LL)sx[y]*sy[y];
        par[y] = x; sx[x]+=sx[y]; sy[x]+=sy[y];
        res += (LL) sx[x]*sy[x];
        E.PB({x,y});
    }
    if(v>=R&&v<R+q) cout<<res<<" ";
    //for(int i=1; i<=3; i++) {
    //    cout<<"x : "<<par[i]<<" , y : "<<par[i+MAXQ]<<"\n";
    //}
    dfs(2*v,E.size());
    dfs(2*v+1,E.size());
    while(E.size()>tmp) {
        pi e = E.back(); E.pop_back();
        par[e.ND] = e.ND;
        sx[e.ST] -= sx[e.ND];
        sy[e.ST] -= sy[e.ND];
    }
    res = pom;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>q;
    for(int i=0; i<q;i++) {
        cin>>t[i].ST.ST>>t[i].ST.ND;
        t[i].ND = i;
    }
    sort(t,t+q);
    R = pow(2,(int)log2(q-1)+1);
    for(int i=0; i<q;i++) {
        if(t[i].ST==t[i+1].ST) {
            update(t[i].ND,t[i+1].ND-1,t[i].ST);
            i++;
        }
        else {
            update(t[i].ND,q-1,t[i].ST);
        }
    }
    for(int i=1; i<2*MAXQ; i++) {
        par[i] = i;
        if(i<MAXQ) sx[i]=1;
        else sy[i]=1;
    }
    dfs(1,0);
}