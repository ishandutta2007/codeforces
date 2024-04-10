#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,s[103],t[103],ans[104],added[104];
void add(int x,int z){
    cout<<"+ "<<x<<endl;
    added[x]++;
    int y;
    cin>>x>>y;
    t[z]=x;
    s[z]=y;
}
int get(int x){
    rep(i,1,105){
        if(i*(i-1)/2==x){
            return i;
        }
    }
    return -1;
}
void pre(){
    int cnt=1;
    add(2,cnt++);
    add(1,cnt++);
    add(3,cnt++);
    add(1,cnt++);
    if(t[4]!=t[3]) ans[1]=get(t[4]-t[3])-1;
    else ans[1]=0;
    ans[2]=s[4]-s[3]-s[2]+s[1]-1;
    ans[3]=(s[4]-s[3])/(ans[2]+1)-1;
    s[2]=s[4]-(ans[2]+1)-(s[3]-s[2]);
    s[3]=s[4];
    t[3]=t[4];
    ans[1]+=added[1];
    ans[2]+=added[2];
}
void solve(){
    cin>>n>>t[0]>>s[0];
    memset(ans,-1,sizeof ans);
    pre();
    rep(i,4,n){
        add(i,i);
        if(t[i]!=t[i-1]) ans[i]=get(t[i]-t[i-1]);
        else ans[i]=-1;
    }
    rep(i,3,n){
        int del=s[i]-s[i-1]-ans[i-2]*ans[i-1];
        if(ans[i+1]==-1){
            if(del==0) ans[i+1]=0;
            else if(i+1==n) ans[i+1]=del/ans[i-1];
            else ans[i+1]=1;
        }
        ans[i]++;
    }
    cout<<"! ";
    rep(i,1,n+1) cout<<ans[i]-added[i]<<" ";
    cout<<endl;
}

signed main(){
    solve();
    return 0;
}