#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N=2e3+5;
ll n,m,k,m1,m2,a,ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(m1<=a){
            m2=m1;
            m1=a;
        }
        else if(m2<=a) m2=a;
    }
    ans=m/(k+1LL)*(k*m1+m2);
    ans+=m%(k+1LL)*m1;
    cout<<ans;
    return 0;
}