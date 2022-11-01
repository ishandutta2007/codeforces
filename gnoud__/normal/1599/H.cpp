#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forb(i,BS) for(int i=BS._Find_first();i< BS.size();i = BS._Find_next(i))
#define timer 1.0*clock()/CLOCKS_PER_SEC
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
int oo=1000000000;
map<int,map<int,int>> que;
int f(int i,int j) {
    if(que[i][j]) return que[i][j];
    cout<<'?'<<" "<<i<<" "<<j<<"\n";
    int x;
    cin>>x;
    return que[i][j]=x;
}
main() {
    int l=2,r=1e9-1,x,y;
    int kc=f(1,1)-f(1,oo);
    if(oo>=0) r=(oo+kc+1)/2;
    else r=(oo+1-kc)/2;
    int yes=f(1,r);
    while(l<=r) {
        int mid=(l+r)/2;
        if(f(1,mid)==yes) {
            x=f(1,mid)+1;
            y=mid,r=mid-1;
        }
        else l=mid+1;
    }
    int v=1000000000+(x-1)-f(1,1000000000);
    int u=1000000000+(y-1)-f(1000000000,1);
    cout<<"!"<<" "<<x<<" "<<y<<" "<<u<<" "<<v<<"\n";
}