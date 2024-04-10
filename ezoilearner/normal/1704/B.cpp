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

int n,t,x;
#define Maxn 200010
int a[Maxn];

int main(){
    rd(t);
    while(t--){
        rd(n);rd(x);
        rep(i,1,n)rd(a[i]);int ans=-1;
        for(int i=1,j;i<=n;i=j+1){
            int l=a[i]-x,r=a[i]+x;
            j=i;
            while(j+1<=n){
                int tl=a[j+1]-x,tr=a[j+1]+x;
                if(max(l,tl)<=min(r,tr)){
                    j++;
                    l=max(l,tl);
                    r=min(r,tr);
                }else break;
            }
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}