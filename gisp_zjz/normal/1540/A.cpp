#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int>pi;
const int maxn=1e6+10;
int n,_,a[maxn];
ll ans;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n); ans=0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++){
            if (i>2) ans+=1ll*(i-2)*a[i];
            if (i<n-1) ans-=1ll*(n-1-i)*a[i];
        }
        printf("%lld\n",-ans);
    }
    return 0;
}