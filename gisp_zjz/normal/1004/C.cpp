#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
typedef long long ll;
ll a[maxn],x[maxn],y[maxn],ans,n,p,u,v;
set <ll> s,t;

int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++){
        if (s.find(a[i])==s.end()) x[u++]=i,s.insert(a[i]);
    }
    for (int i=n;i>=1;i--){
        if (t.find(a[i])==t.end()) y[v++]=i,t.insert(a[i]);
    }
    p=v;
    for (int i=0;i<u;i++){
        while (p&&x[i]>=y[p-1]) p--;
        ans+=p;
    }
    cout << ans << endl;
}