#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cout<<(k>>20)<<endl;}

const int mxn=2e5+3;
int n,a[mxn];
int cal(int s){
    if(s>=n)return 0;
    int cc=1,x=a[s+1],p=s+1;
    while(p<n){
        if(a[p+1]>=2*x-a[s])++cc,++p;
        else{
            p=lower_bound(a+1,a+n+1,2*x-a[s])-a;
            if(p<=n)++cc;
        }
        x=a[p];
    }
    return cc;
}
int main(){
    int ca;cin>>ca;while(ca--){
        scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);
        int re=1;
        for(int l=1,r;l<=n;l=r+1){
            r=l;while(r!=n&&a[r+1]==a[l])++r;
            re=max(re,cal(r)+r-l+1);
        }
        printf("%d\n",n-re);
    }
    return 0;
}