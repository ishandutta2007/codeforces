#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=3e5+12;
int n,m,a[maxn],c[maxn],cc[maxn],ans;
int main(){
    cin >> n >> m;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    if (n>m){
        puts("0");
        return 0;
    }
    ans=1;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            ans=1ll*ans*abs(a[i]-a[j])%m;
    cout << ans << endl;
}