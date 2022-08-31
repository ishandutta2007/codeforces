#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define y1 sdajiopfoaisjdiofjsaoidjifoasjdofijsaoijdfioja
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
vector<pi> ans;
const int maxn=3e6+10;
ll x1,x2,y1,y2,n,X,Y;
ll a[maxn],b[maxn];
void work(ll x,ll y){
    ll g=abs(__gcd(x,y));
    x/=g; y/=g;
    for (int i=1;i<g;i++) printf("%lld %lld\n",x*i,y*i);
}
int main(){
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1<0) x1=-x1,y1=-y1;
    if (x2<0) x2=-x2,y2=-y2;
    if (x1*y2==x2*y1){puts("NO");return 0;}
    if (x1*y2>x2*y1) swap(x1,x2),swap(y1,y2);
    if (x2*y1-x1*y2!=n){puts("NO");return 0;}
    ans.pb((pi){0,0});
    X=x1+x2; Y=y1+y2;
    puts("YES");
    puts("0 0");
    work(x1,y1);
    work(x2,y2);
    work(X,Y);
    for (int i=1;i<=X;i++) a[i]=floor((double)i*Y/X);
    for (int i=1;i<=x1;i++) b[i]=ceil((double)i*y1/x1);
    for (int i=1;i<=x2;i++) b[i+x1]=ceil((double)i*y2/x2)+y1;
    for (ll i=1;i<=X;i++)
    for (ll j=a[i]+1;j<=b[i]-1;j++){
        printf("%lld %lld\n",i,j);
        printf("%lld %lld\n",X-i,Y-j);
    }
    return 0;
}