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

const int mxn=1e5+3;
char s[mxn];int n,qn;
struct mat{
    int a[3][3];
    mat(){memset(a,0x3f,sizeof(a));}
    void ii(int t){
        memset(a,0x3f,sizeof(a));
        a[0][0]=a[1][1]=a[2][2]=0;
        if(t==0)a[0][1]=0,a[0][0]=1;
        else if(t==1)a[1][2]=0,a[1][1]=1;
        else if(t==2)a[2][2]=1;
    }
    mat operator*(const mat&b)const{
        mat r=mat();
        for(int k=0;k<=2;++k)for(int i=0;i<=2;++i)for(int j=0;j<=2;++j)r.a[i][j]=min(r.a[i][j],a[i][k]+b.a[k][j]);
        return r;
    }
    int gg(){return min(a[0][0],min(a[0][1],a[0][2]));}
};
#define mid ((l+r)>>1)
struct seeee{
    mat b[mxn*4];
    void bu(int x=1,int l=1,int r=n){
        b[x]=mat();
        if(l==r)return b[x].ii(s[l]-'a');
        bu(x*2,l,mid),bu(x*2+1,mid+1,r);
        up(x);
    }
    void up(int x){b[x]=b[x*2]*b[x*2+1];}
    void ch(int k,int c,int x=1,int l=1,int r=n){
        if(l==r)return b[x].ii(c),void();
        if(k<=mid)ch(k,c,x*2,l,mid);else ch(k,c,x*2+1,mid+1,r);
        up(x);
    }   
}se;
#undef mid

int main(){
    cin>>n>>qn;scanf("%s",s+1);se.bu();while(qn--){
        int x;char ss[6];scanf("%d%s",&x,ss);se.ch(x,ss[0]-'a');
        printf("%d\n",se.b[1].gg());
    }   
    return 0;
}