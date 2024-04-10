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
mt19937 rnd(time(0));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=2e5+3,sq=500;
int n,a[mxn],b[mxn],m,ee[sq][sq],ti[mxn],s[mxn];
void add(int x,int l,int t){if(x>m)return;x=max(x,l);s[x]+=t;}
int main(){
    cin>>n>>m;for(int i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
    for(int t=1;t<=m;++t){
        int o,x;scanf("%d%d",&o,&x);if(o==1){
            ti[x]=t;int h=a[x]+b[x];
            if(h>=sq){
                for(int e=t+a[x];e<=m;e+=h)add(e,t,1),add(e+b[x],t,-1);
            }else{
                for(int i=t+a[x];i<t+h;++i)++ee[h][i%h];
            }
        }else{
            int tt=ti[x],h=a[x]+b[x];
            if(h>=sq){
                for(int e=tt+a[x];e<=m;e+=h)add(e,t,-1),add(e+b[x],t,1);
            }else{
                for(int i=tt+a[x];i<tt+h;++i)--ee[h][i%h];
            }
        }
        s[t]+=s[t-1];int re=s[t];
        for(int i=1;i<sq;++i)re+=ee[i][t%i];
        printf("%d\n",re);
    }
    return 0;
}