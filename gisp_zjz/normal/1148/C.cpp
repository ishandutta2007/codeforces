#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=5e5+3;
typedef pair<int,int> pi;
vector <pi> ans;
const ll INF=1e15;
int a[maxn],n,p[maxn],b[maxn];
void _swap(int x,int y){
    ans.pb((pi){x,y});
    p[a[x]]=y; p[a[y]]=x;
    swap(a[x],a[y]);
}
void solve(int x){
    if (p[x]==x) return;
    if (x<=n/2&&p[x]>n/2) _swap(p[x],1),_swap(1,n),_swap(n,x);
    else if (x>n/2&&p[x]<=n/2) _swap(p[x],n),_swap(n,1),_swap(1,x);
    else if (x<=n/2&&p[x]<=n/2) _swap(p[x],n),_swap(n,x);
    else _swap(p[x],1),_swap(1,x);
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        p[a[i]]=i; b[i]=a[i];
    }
    for (int i=n/2;i;i--) {
        solve(i);
        solve(n-i+1);
    }
    cout << ans.size() << endl;
    for (auto x:ans) cout << x.F << ' ' << x.S << endl;
    for (auto x:ans) {
        swap(b[x.F],b[x.S]);
        assert(abs(x.F-x.S)>=n/2);
    }
    for (int i=1;i<=n;i++) assert(b[i]==i);
    return 0;
}