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

const int mxn=1e4+3;
int n;
int ask(int x){printf("? %d\n",x);fflush(stdout);cin>>x;return x;}
bool vs[mxn];int to[mxn],b[mxn],m;

void slv(){
    cin>>n;memset(vs,0,sizeof(vs));for(int i=1,c=0;i<=n;++i)if(!vs[i]){
        m=0;for(int x=ask(i);!vs[x];x=ask(i))vs[x]=1,b[m++]=x,++c;
        int p=0;for(int j=0;j<m;++j)if(b[j]==i)p=j;
        for(int k=1,x=i;k<=m;++k)to[x]=b[(p+k)%m],x=to[x];
    }
    printf("! ");for(int i=1;i<=n;++i)printf("%d ",to[i]);puts("");
    fflush(stdout);
}

int main(){
    int ca;cin>>ca;while(ca--)slv();
    return 0;
}