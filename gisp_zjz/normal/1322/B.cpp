#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=1e6+12;
int n,a[maxn],b[maxn],ans;
ll r;
ll calc(int x){
    int pos=n;
    ll ret=0;
    for (int i=1;i<=n;i++){
        while (pos>0&&b[i]+b[pos]>=x) --pos;
        ret+=max(0,pos-i);
    }
    return ret;
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=0;i<=26;i++){
        for (int j=1;j<=n;j++) b[j]=a[j]%(1<<(i+1));
        sort(b+1,b+n+1);
        int x=1<<i;
        r=calc(x*4)-calc(x*3)+calc(x*2)-calc(x);
        if (r&1) ans|=1<<i;
    }
    cout << ans << endl;
    return 0;
}