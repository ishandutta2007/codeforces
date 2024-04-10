#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
const int inf=1e9;
const double PI=acos(-1.0);
void add(int &x,int y){
    x+=y; if (x>=M)x-=M;
}
void sub(int &x,int y){
    x-=y; if (x<0) x+=M;
}
vi b;
namespace fft{
    struct num{
        double x,y;
        num() {x=y=0;}
        num(double x,double y):x(x),y(y){}
    };
    inline num operator+(num a,num b) {return num(a.x+b.x,a.y+b.y);}
    inline num operator-(num a,num b) {return num(a.x-b.x,a.y-b.y);}
    inline num operator*(num a,num b) {return num(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
    inline num conj(num a) {return num(a.x,-a.y);}
    int base=1;
    vector<num> roots={{0,0},{1,0}};
    vector<int> rev={0,1};
    const double PI=acosl(-1.0);
    void ensure_base(int nbase){
        if(nbase<=base) return;
        rev.resize(1<<nbase);
        for(int i=0;i<(1<<nbase);i++)
            rev[i]=(rev[i>>1]>>1)+((i&1)<<(nbase-1));
        roots.resize(1<<nbase);
        while(base<nbase){
            double angle=2*PI/(1<<(base+1));
            for(int i=1<<(base-1);i<(1<<base);i++){
                roots[i<<1]=roots[i];
                double angle_i=angle*(2*i+1-(1<<base));
                roots[(i<<1)+1]=num(cos(angle_i),sin(angle_i));
            }
            base++;
        }
    }
    void fft(vector<num> &a,int n=-1){
        if(n==-1) n=a.size();
        assert((n&(n-1))==0);
        int zeros=__builtin_ctz(n);
        ensure_base(zeros);
        int shift=base-zeros;
        for(int i=0;i<n;i++)
            if(i<(rev[i]>>shift))
                swap(a[i],a[rev[i]>>shift]);
        for(int k=1;k<n;k<<=1){
            for(int i=0;i<n;i+=2*k){
                for(int j=0;j<k;j++){
                    num z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }
    vector<num> fa,fb;
    vector<ll> multiply(vector<int> &a, vector<int> &b){
        int need=a.size()+b.size()-1;
        int nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        int sz=1<<nbase;
        if(sz>(int)fa.size()) fa.resize(sz);
        for(int i=0;i<sz;i++){
            int x=(i<(int)a.size()?a[i]:0);
            int y=(i<(int)b.size()?b[i]:0);
            fa[i]=num(x,y);
        }
        fft(fa,sz);
        num r(0,-0.25/sz);
        for(int i=0;i<=(sz>>1);i++){
            int j=(sz-i)&(sz-1);
            num z=(fa[j]*fa[j]-conj(fa[i]*fa[i]))*r;
            if(i!=j) fa[j]=(fa[i]*fa[i]-conj(fa[j]*fa[j]))*r;
            fa[i]=z;
        }
        fft(fa,sz);
        vector<ll> res(need);
        for(int i=0;i<need;i++) res[i]=fa[i].x+0.5;
        return res;
    }
    vector<int> multiply_mod(vector<int> &a,vector<int> &b,int m,int eq=0){
        int need=a.size()+b.size()-1;
        int nbase=0;
        while((1<<nbase)<need) nbase++;
        ensure_base(nbase);
        int sz=1<<nbase;
        if(sz>(int)fa.size()) fa.resize(sz);
        for(int i=0;i<(int)a.size();i++){
            int x=(a[i]%m+m)%m;
            fa[i]=num(x&((1<<15)-1),x>>15);
        }
        fill(fa.begin()+a.size(),fa.begin()+sz,num{0,0});
        fft(fa,sz);
        if(sz>(int)fb.size()) fb.resize(sz);
        if(eq) copy(fa.begin(),fa.begin()+sz,fb.begin());
        else{
            for(int i=0;i<(int)b.size();i++){
                int x=(b[i]%m+m)%m;
                fb[i]=num(x&((1<<15)-1),x>>15);
            }
            fill(fb.begin()+b.size(),fb.begin()+sz,num{0,0});
            fft(fb,sz);
        }
        double ratio=0.25/sz;
        num r2(0,-1),r3(ratio,0),r4(0,-ratio),r5(0,1);
        for(int i=0;i<=(sz>>1);i++){
            int j=(sz-i)&(sz-1);
            num a1=(fa[i]+conj(fa[j]));
            num a2=(fa[i]-conj(fa[j]))*r2;
            num b1=(fb[i]+conj(fb[j]))*r3;
            num b2=(fb[i]-conj(fb[j]))*r4;
            if(i!=j){
                num c1=(fa[j]+conj(fa[i]));
                num c2=(fa[j]-conj(fa[i]))*r2;
                num d1=(fb[j]+conj(fb[i]))*r3;
                num d2=(fb[j]-conj(fb[i]))*r4;
                fa[i]=c1*d1+c2*d2*r5;
                fb[i]=c1*d2+c2*d1;
            }
            fa[j]=a1*b1+a2*b2*r5;
            fb[j]=a1*b2+a2*b1;
        }
        fft(fa,sz);fft(fb,sz);
        vector<int> res(need);
        for(int i=0;i<need;i++){
            ll aa=fa[i].x+0.5;
            ll bb=fb[i].x+0.5;
            ll cc=fa[i].y+0.5;
            res[i]=(aa+((bb%m)<<15)+((cc%m)<<30))%m;
        }
        return res;
    }
    vector<int> square_mod(vector<int> &a,int m){
        return multiply_mod(a,a,m,1);
    }
};
typedef vector<vi> Vi;
Vi solve(int l,int r){
    if (l==r){
        Vi ret(4);
        for (int i=0;i<4;i++) ret[i].resize(1),ret[i][0]=0;
        ret[0][0]=(b[l]>1)?1:(M+1)/2;
        return ret;
    }
    int mid=(l+r)>>1;
    Vi A=solve(l,mid);
    Vi B=solve(mid+1,r);
    Vi ret(4);
    int len=r-l+1;
    for (int i=0;i<4;i++){
        ret[i].resize(r-l+1);
        for (int j=0;j<len;j++) ret[i][j]=0;
    }
    for (int x=0;x<2;x++)
    for (int y=0;y<2;y++)
    for (int z=0;z<2;z++)
    for (int w=0;w<2;w++){
        vi tmp=fft::multiply_mod(A[x*2+y],B[z*2+w],M);
        int o=1;
        if (!y&&b[mid]==1) o*=2;
        if (!z&&b[mid+1]==1) o*=2;
        if (len>3){
            for (int j=0;j<len-1;j++){
                add(ret[x*2+w][j],tmp[j]);
                add(ret[x*2+w][j+1],(ll)o*tmp[j]%M);
            }
        } else if (len==3){
            for (int j=0;j<len-1;j++){
                add(ret[x*2][j],tmp[j]);
                add(ret[x*2+1][j+1],(ll)o*tmp[j]%M);
            }
        } else {
            for (int j=0;j<len-1;j++){
                add(ret[0][j],tmp[j]);
                add(ret[3][j+1],(ll)o*tmp[j]%M);
            }
        }
    }
    return ret;
}
int n,a[maxn],jc[maxn],p2[maxn];
int main(){
    cin >> n; for (int i=1;i<=n;i++) cin >> a[i];
    jc[0]=p2[0]=1; for (int i=1;i<=n;i++) jc[i]=1ll*jc[i-1]*i%M,p2[i]=p2[i-1]*2%M;
    for (int i=1;i<=n;i+=a[i]){
        for (int j=1;j<a[i];j++) if (a[i+j]!=a[i]) {puts("0");return 0;}
        b.pb(a[i]);
    }
    int m=b.size();
    Vi c=solve(0,m-1);
    int ans=0;
    for (int i=0;i<=m-1;i++){
        if (i&1) sub(ans,1ll*jc[m-i]*p2[m-i]%M*((ll)c[0][i]+c[1][i]+c[2][i]+c[3][i])%M);
        else add(ans,1ll*jc[m-i]*p2[m-i]%M*((ll)c[0][i]+c[1][i]+c[2][i]+c[3][i])%M);
        //cout<<((ll)c[0][i]+c[1][i]+c[2][i]+c[3][i])%M<<endl;
    }
    printf("%d\n",ans);
}