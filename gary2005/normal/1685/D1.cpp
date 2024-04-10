/**
 *    author:  gary
 *    created: 26.05.2022 01:33:04
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
int to[202];
int nex[202],pre[202];
int fa[202];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void solve(){
    int n;
    cin>>n;
    rb(i,1,n) fa[i]=i;
    rb(i,1,n){
        int pi;
        cin>>pi;
        to[pi]=i;
        fa[root(pi)]=root(i);
    }
    rb(i,1,n) nex[i]=pre[i]=i;
    rb(i,2,n){
        if(root(i)!=root(i-1)){
            pre[nex[i-1]]=pre[i];
            nex[pre[i]]=nex[i-1];
            pre[i]=i-1;
            nex[i-1]=i;
            fa[root(i)]=root(i-1);
        }
    }
    int now=1;
    rb(i,1,n){
        cout<<to[now]<<" ";
        now=nex[to[now]];
    }
    cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}