#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

struct Node {
    LL g,f;
};

const int nax = 300*1000+1;
int n,x,R,log2n;
LL ww[nax];
LL suf[nax];
Node T[(1<<20)];

void propagate(int a) {
    T[2*a].g+=T[a].g;
    T[2*a+1].g+=T[a].g;
    T[a].g=0;
}

void updateTf(int a) {
    while(a>1) {
        a/=2;
        T[a].f = max(T[2*a].f+T[2*a].g,T[2*a+1].g+T[2*a+1].f);
    }
}

void update(int a,int b,LL c) {
    a+=R; b+=R;
    if(a>b) return;
    if(a<0) return;
    for(int i=log2n; i>0; i--) {
        propagate(a/(1<<i));
        propagate(b/(1<<i));
    }
    int pa=a,pb=b;
    T[a].g+=c;
    if(a!=b) T[b].g+=c;
    while(a/2!=b/2) {
        if(a%2==0) T[a+1].g+=c;
        if(b%2==1) T[b-1].g+=c;
        a/=2;
        b/=2;
    }
    updateTf(pa); updateTf(pb);
}

LL query(int a,int b) {
    a+=R;
    b+=R;
    for(int i=log2n; i>0; i--) {
        propagate(a/(1<<i));
        propagate(b/(1<<i));
    }
    updateTf(a); updateTf(b);
    LL w = max(T[a].g,T[b].g);
    while(a/2!=b/2) {
        if(a%2==0) w=max(w,T[a+1].g+T[a+1].f);
        if(b%2==1) w=max(w,T[b-1].g+T[b-1].f);
        a/=2;
        b/=2;
    }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(int i=0; i<n;i++) {
        cin>>ww[i];
    }
    if(x>0) {
        LL ans =0; LL best=0; LL act=0;
        for(int i=0; i<n;i++) {
            act+=ww[i];
            best=min(best,act);
            ans=max(ans,act-best);
        }
        cout<<(LL)ans*x;
        return 0;
    }
    R = pow(2,(int)log2(n)+1);
    log2n = log2(R);
    LL ans=0,act=0,best=0;
    for(int i=n-1; i>=0; i--) {
        act+=ww[i];
        best=min(best,act);
        suf[i]=act-best;
    }
    act=0; best=0;
    for(int i=0; i<n;i++) {
        act+=ww[i];
        update(0,i,(LL)ww[i]*x);
        best=min(best,act);
        update(i+1,i+1,act-best);
        LL tmp = query(0,i);
        //cout<<tmp<<" "<<suf[i+1]<<"\n";
        ans=max(ans,tmp+suf[i+1]);
    }
    ans=max(ans,query(0,n));
    cout<<ans;
}