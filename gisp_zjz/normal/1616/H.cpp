#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int p2[maxn],n,k;
vi A;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
int solve2(vi &p,vi &q,int x){
    if (!p.size()||!q.size()) return 0;
    if (x==-1) return 1ll*p2[p.size()]*p2[q.size()]%M;
    vi a,b,c,d; a.clear(); b.clear(); c.clear(); d.clear();
    for (auto v:p){
        if ((v>>x)&1) a.pb(v); else b.pb(v);
    }
    for (auto v:q){
        if ((v>>x)&1) c.pb(v); else d.pb(v);
    }
    if (!((k>>x)&1)) return (solve2(a,c,x-1)+solve2(b,d,x-1))%M;
    int ret=0;
    int pp=solve2(a,d,x-1);
    int qq=solve2(b,c,x-1);
    add(ret,pp);
    add(ret,qq);
    add(ret,1ll*pp*qq%M);
    add(ret,1ll*pp*p2[b.size()]%M);
    add(ret,1ll*pp*p2[c.size()]%M);
    add(ret,1ll*qq*p2[a.size()]%M);
    add(ret,1ll*qq*p2[d.size()]%M);
    add(ret,1ll*p2[a.size()]*p2[c.size()]%M);
    add(ret,1ll*p2[b.size()]*p2[d.size()]%M);
    return ret;
}
int solve1(vi &a,int x){
    if (!a.size()) return 0;
    if (x==-1) return p2[a.size()];
    vi p,q; p.clear(); q.clear();
    for (auto v:a){
        if ((v>>x)&1) p.pb(v); else q.pb(v);
    }
    if ((k>>x)&1){
        int ret=solve2(p,q,x-1);
        add(ret,p2[p.size()]);
        add(ret,p2[q.size()]);
        return ret;
    } else {
        return (solve1(p,x-1)+solve1(q,x-1))%M;
    }
}
int main(){
    p2[0]=0; for (int i=1;i<maxn;i++) p2[i]=(p2[i-1]*2+1)%M;
    cin >> n >> k;
    A.resize(n);
    for (int i=0;i<n;i++) cin >> A[i];
    cout << solve1(A,29) << endl;
}