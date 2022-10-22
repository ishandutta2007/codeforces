#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

struct Node {
    int f,g;
};

const int nax = 200*1000+10,INF=1e9;
int n;
int a[2*nax];
int nxtl[nax], nxtr[nax], inv[nax];
Node T[(1<<20)];
set<int>pos;

void propagate(int x) {
    T[2*x].g+=T[x].g;
    T[2*x+1].g+=T[x].g;
    T[x].g = 0;
}

void update(int a,int b,int x,int v,int l,int r) {
    if(a<=l&&r<=b) {
        T[v].g+=x;
        return;
    }
    propagate(v);
    int mid = (l+r)/2;
    if(a<=mid) update(a,b,x,v*2,l,mid);
    if(mid<b) update(a,b,x,v*2+1,mid+1,r);
    T[v].f = max(T[2*v].f+T[2*v].g,T[2*v+1].f+T[2*v+1].g);
}

int query(int a,int b,int v,int l,int r) {
    if(a<=l&&r<=b) {
        return T[v].f+T[v].g;
    }
    propagate(v);
    int mid = (l+r)/2;
    int w = -1;
    if(a<=mid) w=max(w,query(a,b,v*2,l,mid));
    if(mid<b) w=max(w,query(a,b,v*2+1,mid+1,r));
    T[v].f = max(T[2*v].f+T[2*v].g,T[2*v+1].f+T[2*v+1].g);
    return w;
}

pi ans = {INF,-1};

int main() {_
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        a[i+n] = a[i];
        inv[a[i]] = i;
    }
    vi S = {2*n+1};
    for(int i=n; i>=1; --i) {
        while(a[S.back()]>a[i]) S.pop_back();
        nxtr[i+n] = S.back();
        S.PB(i+n);
    }
    for(int i=n; i>=1; --i) {
        while(a[S.back()]>a[i]) S.pop_back();
        nxtr[i] = S.back();
        S.PB(i);
    }
    S = {0};
    for(int i=1; i<=n; i++) {
        while(a[S.back()]>a[i]) S.pop_back();
        S.PB(i);
    }
    for(int i=n+1; i<=2*n; i++) {
        while(a[S.back()]>a[i]) S.pop_back();
        nxtl[i] = S.back();
        S.PB(i);
    }
    pos.insert(0); pos.insert(n+1);
    for(int i=1; i<=n; i++) {
        auto it = pos.lower_bound(inv[i]);
        it--;
        int x = (*it);
        it++;
        int y = (*it);
        update((x)+1,y-1,1,1,1,2*n);
        pos.insert(inv[i]);
    }
    //for(int i=1; i<=n; i++) cout<<query(i,i,1,1,2*n)<<" ";
    //cout<<"\n";
    for(int i=0; i<n; i++) {
        int w = query(i+1,n+i,1,1,2*n);
        //cout<<w<<" ";
        ans = min(ans,{w,i});
        update(i+1,nxtr[i+1]-1,-1,1,1,2*n);
        update(nxtl[i+1+n]+1,i+1+n,1,1,1,2*n);
        int val = query(nxtl[i+1+n],nxtl[i+1+n],1,1,2*n);
        //cout<<nxtl[i+1+n]<<" ";
        //cout<<val<<"\n";
        update(i+1+n,i+1+n,val,1,1,2*n);
    }
    cout<<ans.ST<<" "<<ans.ND;
}