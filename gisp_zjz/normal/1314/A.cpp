#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int maxn=2e5+3;
typedef pair<ll,ll> pi;
priority_queue <ll> q;
int n;
pi a[maxn];
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i].F;
    for (int i=1;i<=n;i++) cin >> a[i].S;
    sort(a+1,a+n+1);
    ll ans=0,pos=a[1].F,sum=0,id=1;
    while (id<=n||!q.empty()){
        while (a[id].F==pos){
            sum+=a[id].S;
            q.push(a[id].S);
            ++id;
        }
        sum-=q.top(); q.pop();
        ans+=sum;
        pos++;
        if (id<=n&&q.empty()&&pos<a[id].F) pos=a[id].F;
    }
    cout << ans << endl;
}