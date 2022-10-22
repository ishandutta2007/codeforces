#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL INF = (LL)1000*1000*1000*1000*1000*1000;
const int MAXN = 1000*100+1;
int n,q,R,log2n;
LL tab[MAXN];
LL p[MAXN];

struct Node {
    LL s,m,g,r,t;
    bool gw;
};

Node T[(1<<19)];

void propagate(int x) {
    if(!T[x].gw) return;
    T[2*x].gw = T[2*x+1].gw = 1;
    T[x].gw=0;
    T[2*x].g=T[x].g;
    T[2*x+1].g=T[x].g;
    T[x].g=0;
}

void updateTf(int a) {
    while(a>1) {
        a/=2;
        if(T[2*a].gw) {
            T[a].m = T[2*a].g;
            T[a].s = (LL)T[2*a].g*T[2*a].r;
        }
        else {
            T[a].m = T[2*a].m;
            T[a].s = T[2*a].s;
        }
        if(T[2*a+1].gw) {
            T[a].m = max(T[a].m,T[2*a+1].g);
            T[a].s+=(LL)T[2*a+1].g*T[2*a+1].r;
        }
        else {
            T[a].m=max(T[a].m,T[2*a+1].m);
            T[a].s+=T[2*a+1].s;
        }
    }
}

int get_border(LL val) {
    int v=1;
    while(v<R) {
        LL m1;
        if(T[2*v].gw) m1 = T[2*v].g;
        else m1 = T[2*v].m;
        if(m1<=val) v=2*v+1;
        else v*=2;
    }
    return v-R;
}

void update(int a,int b,LL c) {
    a+=R; b+=R;
    for(int i=log2n; i>0;i--) {
        propagate(a/(1<<i));
        propagate(b/(1<<i));
    }
    int pa=a,pb=b;
    T[a].g = T[b].g = c;
    T[a].gw = T[b].gw = 1;
    while(a/2!=b/2) {
        if(a%2==0) {
            T[a+1].g = c;
            T[a+1].gw=1;

        }
        if(b%2==1) {
            T[b-1].g = c;
            T[b-1].gw = 1;
        }
        a/=2;
        b/=2;
    }
    updateTf(pa);
    updateTf(pb);
}

LL query(int a,int b) {
    a+=R; b+=R;
    for(int i=log2n; i>0;i--) {
        propagate(a/(1<<i));
        propagate(b/(1<<i));
    }
    updateTf(a);
    updateTf(b);
    LL w = T[a].t;
    if(a!=b) w+=T[b].t;
    if(T[a].gw) w+=T[a].g;
    if(a!=b&&T[b].gw) w+=T[b].g;
    while(a/2!=b/2) {
        if(a%2==0) {
            if(T[a+1].gw) {
                w+=(LL)T[a+1].g*T[a+1].r;
            }
            else {
                w+=T[a+1].s;
            }
            w+=T[a+1].t;
        }
        if(b%2==1) {
            if(T[b-1].gw) {
                w+=(LL)T[b-1].g*T[b-1].r;
            }
            else {
                w+=T[b-1].s;
            }
            w+=T[b-1].t;
        }
        a/=2;
        b/=2;
    }
    return w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) cin>>tab[i];
    for(int i=1; i<n; i++) {
        LL a;
        cin>>a;
        p[i] = p[i-1]+a;
    }
    R = pow(2,(int)log2(n)+1);
    log2n = log2(R);
    for(int i=R; i<R+n;i++) {
        T[i].r=1;
        T[i].t = p[i-R];
        T[i].m = -INF;
    }
    for(int i=R-1; i>0;i--) {
        T[i].r = T[2*i].r+T[2*i+1].r;
        T[i].t = T[i*2].t+T[i*2+1].t;
    }
    for(int i=0; i<n;i++) update(i,i,tab[i]-p[i]);
    cin>>q;
    for(int i=0; i<q;i++) {
        char c;
        int a,b;
        cin>>c>>a>>b;
        if(c=='s') {
            cout<<query(a-1,b-1)<<"\n";
        }
        else {
            LL val = (LL)query(a-1,a-1)-T[a-1+R].t+b;
            int pos = get_border(val);
            update(a-1, pos-1,val);
        }
    }
    return 0;
}