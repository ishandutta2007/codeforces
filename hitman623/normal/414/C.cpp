#include <bits/stdc++.h>

#define int         long long
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
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,a[1<<20],b[1<<20],ans[22],same[22];
void sol(int h,int l,int r){
    if(l==r) return;
    int mid=(l+r)>>1;
    sol(h+1,l,mid);
    sol(h+1,mid+1,r);
    int in1=l,in2=mid+1,cur=in1;
    while(in1<=mid and in2<=r){
        if(a[in1]<=a[in2]) b[cur++]=a[in1++];
        else b[cur++]=a[in2++],ans[h]+=(mid-in1+1);
    }
    while(in1<=mid) b[cur++]=a[in1++];
    while(in2<=r) b[cur++]=a[in2++];
    mi mp;
    rep(i,l,mid+1) mp[a[i]]++;
    rep(i,mid+1,r+1) same[h]+=mp[a[i]];
    rep(i,l,r+1) a[i]=b[i];
}
void solve(){
    cin>>n;
    rep(i,0,1<<n){
        cin>>a[i];
    }
    sol(0,0,(1<<n)-1);
    cin>>m;
    rep(i,0,m){
        int x,res=0;
        cin>>x;
        rep(j,n-x,n){
            int g=1<<(n-j-1);
            ans[j]=(1<<j)*(g*g)-ans[j]-same[j];
        }
        rep(j,0,n+1) res+=ans[j];
        cout<<res<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}