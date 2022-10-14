/**
 *    author:  gary
 *    created: 27.03.2022 18:39:20
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
const int MAXN=2e5+10;
int n,a[MAXN],p[MAXN],fa[MAXN];
vector<int> app[MAXN],pos[MAXN];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void solve(){
    cin>>n;
    rb(i,1,n) fa[i]=i;
    rb(i,1,n) app[i].clear(),pos[i].clear();
    rb(i,1,n) cin>>a[i],app[a[i]].PB(i);
    int odd=-1;
    rb(i,1,n) if(app[i].size()%2){
        if(odd!=-1){
            cout<<"NO\n";
            return ;
        }
        else odd=i;
    }
    if(odd==-1){
        int l=1,r=n;
        rb(i,1,n){
            while (app[i].size()>=1)
            {
                if(app[i].size()%2) p[l++]=app[i].back();
                else p[r--]=app[i].back();
                app[i].pop_back();
            }
        }
    }
    else{
        int l=1,r=n;
        rb(i,1,n){
            if(i!=odd)
            while (app[i].size()>=1)
            {
                if(app[i].size()%2) p[l++]=app[i].back();
                else p[r--]=app[i].back();
                app[i].pop_back();
            }
        }
        for(auto it:app[odd]) p[l++]=it;
    }
    rb(i,1,n) fa[root(i)]=root(p[i]);
    rb(i,1,n) pos[a[p[i]]].PB(i);
    rb(i,1,n){
        int pr=-1;
        for(auto it:pos[i]){
            if(pr!=-1&&root(it)!=root(pr)){
                fa[root(it)]=root(pr);
                swap(p[pr],p[it]);
            }
            pr=it;
        }
    }
    if(odd!=-1&&pos[odd].size()==1){
        if(p[(n+1)/2]==(n+1)/2){
            cout<<"NO\n";
            return;
        }
    }
    rb(i,1,n/2){
        if(root(i)!=root(i+1)){
            swap(p[i],p[i+1]);
            swap(p[n-i+1],p[n-i]);
            swap(p[i],p[n-i+1]);
            fa[root(i)]=root(i+1);
        }
    }
    cout<<"YES\n";
    rb(i,1,n) cout<<p[i]<<" ";
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