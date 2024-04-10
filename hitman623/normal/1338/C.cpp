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
int v1[]={0,2,3,1};
int get0(int n){
    n++;
    int cnt=0;
    for(int i=0;i<=55;i+=2){
        int l=1*(1LL<<i);
        int r=2*(1LL<<i)-1;
        if(cnt+1<=n and n<=cnt+r-l+1){
            return l+n-cnt-1;
        }
        cnt+=r-l+1;
    }
    return -1;
}
int get(int l,int n){
    if(n==0 or l==1) return 0;
    int d=l/4;
    return v1[n/d]*d+get(d,n%d);
}
int get1(int n){
    n++;
    int cnt=0;
    for(int i=0;i<=55;i+=2){
        int l=2*(1LL<<i);
        int r=3*(1LL<<i)-1;
        if(cnt+1<=n and n<=cnt+r-l+1){
            return l+get(r-l+1,n-cnt-1);
        }
        cnt+=r-l+1;
    }
    return -1;
}
void solve(){
    int n;
    cin>>n;
    n--;
    int a=get0(n/3);
    int b=get1(n/3);
    if(n%3==0) cout<<a<<endl;
    else if(n%3==1) cout<<b<<endl;
    else cout<<(a^b)<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}