#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,q,m,p[10],a[maxn],r[10];
//multiset<ll> S[10];
priority_queue<pi> S[10];
ll s[10][maxn];
void upd(int x,int y){
    for (int i=1;i<=m;i++){
        int j=x%r[i];
        s[i][j]+=y-a[x];
        S[i].push((pi){s[i][j],j});
    }
    a[x]=y;
}
ll qry(){
    ll res=0;
    for (int i=1;i<=m;i++){
        ll tmp=0;
        while (!S[i].empty()){
            pi top=S[i].top();
            if (s[i][top.S]==top.F) {tmp=top.F;break;}
            S[i].pop();
        }
        res=max(res,tmp*r[i]);
    }
    return res;
}
mt19937_64 gen(time(0));
void solve(){
    cin >> n >> q;
    //n=180180; q=0;
    m=0; int tmp=n;
    for (int i=2;i*i<=tmp;i++){
        if (tmp%i==0){
            p[++m]=i;
            while (tmp%i==0) tmp/=i;
        }
    }
    if (tmp>1) p[++m]=tmp;
    for (int i=1;i<=m;i++){
        r[i]=n/p[i]; 
        for (int j=0;j<r[i];j++) s[i][j]=0;
        while (!S[i].empty()) S[i].pop();
    }
    for (int i=0;i<n;i++) a[i]=0;
    for (int i=0;i<n;i++){
        int x; //x=gen()%10000;
        cin >> x;
        upd(i,x);
    }
    cout << qry() << endl;
    while (q--){
        int id,x; cin >> id >> x; id--;
        upd(id,x); 
        cout << qry() << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}