#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+10;
const int M=998244353;
const int N=200;
int T=0;
int val[9];
int xa,xb,ya,yb;
int ask(int x,int y){
    //cout<<x<<' '<<y<<endl;
    ++T; assert(T<=4);
    vector<pi> a; a.clear();
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            if (i%x==0&&j%y==0) a.pb((pi){i,j});
    if (!a.size()) return 0;
    printf("? %d\n",a.size());
    for (auto x:a) printf("%d %d ",x.F,x.S); puts("");
    fflush(stdout);
    int ret;scanf("%d",&ret);
    return ret;
}
bool check(int x){
    val[x]=ask(1<<x,1<<x);
    return (val[x]<<(x*2))==val[0];
}
int main(){
    memset(val,-1,sizeof(val));
    int n=ask(1,1); val[0]=n;
    if (n==128*128){puts("! 508");fflush(stdout);return 0;}
    int b=0,tmp=n;
    while (tmp%2==0) b++,tmp>>=1;
    int l=0,r=b/2+1; assert(r<=7);
    while (r-l>1){
        int mid=(l+r+1)>>1;
        if (check(mid)) l=mid; else r=mid;
    }
    if (l*2==b){
        assert(T<=3);
        int m=n>>(l*2);
        int s=ask(1<<l,1<<(l+1));
        int x=abs(s-(m-s)),y=m/x;
        printf("! %d\n",((x+y)<<(l+1))-4);
        fflush(stdout);
        return 0;
    }
    int m=n>>(l*2);
    if (val[r]==-1) check(r);
    int x=2*abs(val[r]-(m/2-val[r])),y=m/x;
    printf("! %d\n",((x+y)<<(l+1))-4);
    fflush(stdout);
    return 0;
}