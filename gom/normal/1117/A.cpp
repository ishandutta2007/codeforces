#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
struct st{ int x,y,t; };
const int N=2e3+5;
int n,ans,mx=-1,bf=0,a;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(mx<a){
            ans=1;
            mx=a;
            bf=1;
        }
        else if(mx==a){
            bf++;
            ans=max(ans,bf);
        }
        else bf=0;
    }
    cout<<ans;
}