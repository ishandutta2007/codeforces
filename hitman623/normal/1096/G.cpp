#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        998244353 
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
const int mod=998244353;    
const int root=565042129;   // nth root of mod
const int root_1=950391366; // inverse of root
const int root_pw=1<<20;    // value of n
void fft(vi&a,bool invert){
    int i,j,n=(int)a.size();
    for(i=1,j=0;i<n;++i){
        int bit=n>>1;
        for(;j>=bit;bit>>=1){
            j-=bit;
        }
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len<<=1){
        int wlen=invert?root_1:root;
        for(i=len;i<root_pw;i<<=1){
            wlen=(wlen*wlen%hell);
        }
        for(i=0;i<n;i+=len){
            int w=1;
            for(j=0;j<len/2;++j){
                int u=a[i+j],v=(int)(a[i+j+len/2]*w%hell);
                a[i+j]=(u+v+hell)%hell;
                a[i+j+len/2]=(u-v+hell)%hell;
                w=(w*wlen%hell);
            }
        }
    }
    if(invert){
        int nrev=expo(n,hell-2,hell);
        for(i=0;i<n;++i){
            a[i]=(a[i]*nrev%hell);
        }
    }
}
void multiply(const vi &a,const vi &b,vi &res){
    vi fa(a.begin(),a.end()),fb(b.begin(),b.end());
    size_t n=1;
    while(n<max(a.size(),b.size())) n<<=1;
    n<<= 1;
    fa.resize(n),fb.resize(n);
    fft(fa,false),fft(fb,false);
    for(size_t i=0;i<n;++i){
        fa[i]*=fb[i];
    }
    fft(fa,true);
    res.resize(n);
    for(size_t i=0;i<n;++i){
        res[i]=fa[i];
    }
}
int n,k,d[11];
vi pol(1<<20);
void solve(){
    cin>>n>>k;
    rep(i,0,k) cin>>d[i],pol[d[i]]++;
    fft(pol,0);
    rep(i,0,1<<20){
        pol[i]=expo(pol[i],n/2,hell);
    }
    fft(pol,1);
    int ans=0;
    rep(i,0,1<<20){
        ans=(ans+(pol[i]*pol[i])%hell)%hell;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}