#include<bits/stdc++.h>
#define maxn 123456

using namespace std;
typedef long long ll;
ll a,b,c,n,m,r,S;
vector <ll> f,g;

int main(){
    cin >> a >> b >> c; n=a; m=b;
    r=__gcd(b,c); b/=r; c/=r;
    r=__gcd(a,c); a/=r; c/=r;
    if (c>2) {puts("NO");return 0;} b=b*2/c;
    for (ll i=1;i*i<=a;i++) if (a%i==0) f.push_back(i),f.push_back(a/i);
    for (ll i=1;i*i<=b;i++) if (b%i==0) g.push_back(i),g.push_back(b/i);
    S=a*b;
    for (int i=0;i<f.size();i++) for (int j=0;j<g.size();j++){
        a=f[i]*g[j];
        b=S/a;
        if (a<=n&&b<=m){
            puts("YES");
            printf("0 0\n");
            printf("%I64d 0\n",a);
            printf("0 %I64d\n",b);
            return 0;
        }
    }
    puts("NO");
}