#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}

int n,m;
#define Maxn 100010
int a[Maxn],b[Maxn],cnt=0;

int main(){
    int t;rd(t);
    while(t--){
        rd(n);rd(m);
        rep(i,1,m)rd(a[i]);
        sort(a+1,a+m+1);
        cnt=0;
        rep(i,2,m)
            if(a[i]>a[i-1]+1)b[++cnt]=a[i]-a[i-1]-1;
        if(n-a[m]+a[1]-1)b[++cnt]=n-a[m]+a[1]-1;
        int T=0,ans=0;
        sort(b+1,b+cnt+1);
        per(i,cnt,1){
            b[i]-=2*T;
            if(b[i]<=0)break;
            if(b[i]<=2){
                T++;
                ans++;
            }else{
                T+=2;
                ans+=b[i]-1;
            }
        }
        printf("%d\n",n-ans);
    }
    return 0;
}