/**
 *    author:  gary
 *    created: 12.12.2021 23:51:11
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n,a[500000+20],b[500000+20];
int fa[500000+20];
int siz[500000+20];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void solve(){
    cin>>n;
    rb(i,1,n) fa[i]=i,siz[i]=0;
    rb(i,1,n) cin>>a[i],b[i]=a[i];
    sort(b+1,b+1+n);
    if(n==1){
        cout<<"YES\n";
        return ;
    }
    if(n==2){
        if(a[1]<=a[2]){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        return ;
    }
    rb(i,2,n){
        if(b[i]==b[i-1]){
            cout<<"YES\n";
            return ;
        }
    }
    map<int,int> M;
    rb(i,1,n) M[a[i]]=i;
    rb(i,1,n) fa[root(i)]=root(M[b[i]]);
    rb(i,1,n) siz[root(i)]++;
    int cnt=0;
    rb(i,1,n) if(siz[i]%2==0&&siz[i]){
        cnt++;
    }
    if(cnt%2==0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
int main(){
    // freopen("out.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}