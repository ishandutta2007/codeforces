#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=3e5+12;
int M1,M2,cnt[maxn],n,q,m;
pi f[maxn],g[maxn],p2[maxn];
char s[maxn];
mt19937_64 gen(time(0));
bool isprime(int x){
    for (int j=2;j*j<=x;j++) if (x%j==0) return 0;
    return 1;
}
int getprime(int l,int r){
    int x=gen()%(r-l+1);
    x=x+l;
    while (!isprime(x)) ++x;
    return x;
}
void getp(){
    M1=getprime(4e8,5e8);
    M2=getprime(7e8,8e8);
}
pi add(pi x,pi y){
    return (pi){(x.F+y.F)%M1,(x.S+y.S)%M2};
}
pi sub(pi x,pi y){
    return (pi){(x.F-y.F+M1)%M1,(x.S-y.S+M2)%M2};
}
pi mut(pi x,pi y){
    return (pi){1ll*x.F*y.F%M1,1ll*x.S*y.S%M2};
}
pi gethash(int l,int r,int o){
    if (o==0) return sub(f[r],mut(f[l],p2[r-l]));
    else return sub(g[r],mut(g[l],p2[r-l]));
}
int main(){
    getp();
    scanf("%d%s",&n,s+1);
    for (int i=1;i<=n;i++) cnt[i]=cnt[i-1]+(s[i]=='0');
    p2[0]=(pi){1,1};
    for (int i=1;i<=n+1;i++) p2[i]=add(p2[i-1],p2[i-1]);
    m=0; f[0]=(pi){0,0};
    for (int i=1;i<=n;i++) if (s[i]=='0'){
        ++m;
        int o=i&1;
        f[m]=add(add(f[m-1],f[m-1]),(pi){o,o});
        g[m]=add(add(g[m-1],g[m-1]),(pi){o^1,o^1});
    }
    scanf("%d",&q);
    while (q--){
        int l1,l2,len;
        scanf("%d%d%d",&l1,&l2,&len);
        int L1=cnt[l1-1],R1=cnt[l1+len-1];
        int L2=cnt[l2-1],R2=cnt[l2+len-1];
        pi tmp=gethash(L1,R1,l1&1);
        tmp=gethash(L2,R2,l2&1);
        if (R1-L1!=R2-L2){
            puts("No");
        } else {
            if (gethash(L1,R1,l1&1)==gethash(L2,R2,l2&1)) puts("Yes");
            else puts("No");
        }
    }
}