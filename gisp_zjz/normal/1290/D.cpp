#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=3e5+10;
int tot=0;
int n,k,m,L[1045],R[1045];
vector <int> b[1045];
void reset(){
    puts("R");
    fflush(stdout);
}
bool ask(int x){
    printf("? %d\n",x+1);
    ++tot;
    assert(tot<=3*n*n/(k*2));
    fflush(stdout);
    char c[2];
    scanf("%s",c);
    return c[0]=='Y';
}
vi work(vi &a){
    vi ret; ret.clear();
    for (auto x:a) if (!ask(x)) ret.pb(x);
    reset();
    return ret;
}
vi solve(vi &a,vi &b){
    if (a.size()>b.size()) return solve(b,a);
    if (a.size()==0) return b;
    if (k==1){
        vi ret; ret.clear();
        ask(a[0]); ret.pb(a[0]);
        if (!ask(b[0])) ret.pb(b[0]);
        reset();
        return ret;
    }
    if (b.size()<=k/2){
        vi res; res.clear();
        for (auto x:a) res.pb(x);
        for (auto x:b) res.pb(x);
        return work(res);
    } else if (a.size()<=k/2){
        vi ret; ret.clear();
        for (auto x:a) ret.pb(x);
        while (a.size()<k/2) a.pb(a[0]);
        while (b.size()<k) b.pb(b[k/2]);
        for (int i=0;i<k/2;i++) ask(a[i]);
        for (int i=0;i<k/2;i++) if (!ask(b[i])) ret.pb(b[i]);
        for (int i=0;i<k/2;i++) ask(a[i]);
        for (int i=k/2;i<k;i++) if (!ask(b[i])) ret.pb(b[i]);
        reset();
        return ret;
    } else {
        vi ret; ret.clear();
        while (a.size()<k) a.pb(a[k/2]);
        while (b.size()<k) b.pb(b[k/2]);
        for (int i=0;i<k/2;i++) ask(a[i]);
        for (int i=0;i<k/2;i++) ask(b[i]);
        for (int i=k/2;i<k;i++) if (!ask(a[i])) ret.pb(a[i]);
        for (int i=k/2;i<k;i++) if (!ask(b[i])) ret.pb(b[i]);
        for (int i=0;i<k/2;i++) if (!ask(a[i])) ret.pb(a[i]);
        for (int i=0;i<k/2;i++) if (!ask(b[i])) ret.pb(b[i]);
        reset();
        return ret;
    }
}
int main(){
    cin >> n >> k; m=n/k;
    for (int i=0;i<m;i++){
        vi res; res.clear();
        for (int j=0;j<k;j++) res.pb(i*k+j);
        b[i]=work(res);
        L[i]=i*k; R[i]=(i+1)*k-1;
    }
    for (int j=1;j<m;j++)
    for (int i=0;i<j;i++){
        vi res1,res2; res1.clear(); res2.clear();
        for (auto x:b[i]) res1.pb(x);
        for (auto x:b[j]) res2.pb(x);
        vi res=solve(res1,res2);
        b[i].clear(); b[j].clear();
        for (auto x:res) {
            if (x>=L[i]&&x<=R[i]) b[i].pb(x);
            else b[j].pb(x);
        }
    }
    int ans=0;
    for (int i=0;i<m;i++) ans+=b[i].size();
    printf("! %d\n",ans);
    return 0;
}