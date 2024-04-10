#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
typedef vector<int> vi;
const int inf=1e9+10;
const int maxn=1e6+10;
const int M=998244353;
int kase=0;
int n,a[20],m,d[20];    
pi b[20];
void print(int x){
    for (int i=1;i<=m;i++){
        d[b[i].S]=x%(a[i]+1);
        x/=a[i]+1;
    }
    for (int i=1;i<=m;i++) cout << d[i] << ' '; cout << endl;
}
void work(vi &c,int x){
    if (x==m+1){
        for (int i=0;i<c.size();i++) print(c[i]);
        return;
    }
    int n=c.size();
    if (n==1){
        vi d=(vi){1,3,2};
        work(d,x+1);
        return;
    }
    vi d(n*2+1);
    for (int i=0;i<n-1;i++){
        d[i]=d[n*2-2-i]=c[i];
        if (i%2==0) d[n*2-2-i]+=n+1; else d[i]+=n+1;
    }
    d[n-1]=c[n-1];
    d[n*2-1]=n+1;
    d[n*2]=c[n-1]+(n+1);
    work(d,x+1);
}
void solve(){
    cin >> m;
    for (int i=1;i<=m;i++) cin >> a[i];
    n=1; for (int i=1;i<=m;i++) n=n*(a[i]+1);
    for (int i=1;i<=m;i++) b[i]=(pi){a[i],i};
    sort(b+1,b+m+1); reverse(b+1,b+m+1);
    for (int i=1;i<=m;i++) a[i]=b[i].F;
    if (m>2&&a[3]>1){cout << "-1" << endl; return;}
    if (a[1]>3){
        cout << "-1" << endl; return;
    } if (a[1]==3){
        if (m>1&&a[2]>1){cout << "-1" << endl; return;}
        vi tmp=(vi){2,1,3};
        work(tmp,2);
    } else if (a[1]==2){
        if (m>2&&a[3]>1){cout << "-1" << endl; return;}
        if (m>1&&a[2]>1){
            vi tmp=(vi){2,4,6,5,3,8,1,7};
            work(tmp,3);
        } else {
            vi tmp=(vi){1,2};
            work(tmp,2);
        }
    } else {
        vi tmp=(vi){1};
        work(tmp,2);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _; cin >> _;
    while (_--) solve();
}