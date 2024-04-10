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

const int mxn=5e4+3;
int n;struct thr{int x,y,z,k;}b[mxn];
bool vs[mxn];vector<pii>ans;
bool cmp1(const thr&a,const thr&b){if(a.x!=b.x)return a.x<b.x;if(a.y!=b.y)return a.y<b.y;return a.z<b.z;}
void ee(int x,int y){
    ans.emplace_back(b[x].k,b[y].k),vs[x]=vs[y]=1;
}
void sol(int L,int R){
    for(int l=L,r;l<=R;l=r+1){
        r=l;while(r!=R&&b[r+1].y==b[l].y)++r;
        for(int i=l;i<r;i+=2)ee(i,i+1);
    }
    int t=-1;
    for(int i=L;i<=R;++i)if(!vs[i]){if(t==-1)t=i;else ee(t,i),t=-1;}
}
int main(){
    scanf("%d",&n);for(int i=1,x,y,z;i<=n;++i)scanf("%d%d%d",&x,&y,&z),b[i]={x,y,z,i};
    sort(b+1,b+n+1,cmp1);
    for(int l=1,r;l<=n;l=r+1){
        r=l;while(r!=n&&b[r+1].x==b[l].x)++r;
        sol(l,r);
    }
    int t=-1;
    for(int i=1;i<=n;++i)if(!vs[i]){if(t==-1)t=i;else ee(t,i),t=-1;}
    for(pii k:ans)printf("%d %d\n",k.first,k.second);
    return 0;
}