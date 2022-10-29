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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#define PI 3.141592653589793l
struct base{
    long double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(long double _x){
        x = _x;
        y = 0;
    }
    base(long double _x , long double _y){
        x = _x;
        y = _y;
    }
    inline base operator + (const base &o) const {
        return base(x + o.x , y + o.y);
    }
    inline base operator - (const base &o) const {
        return base(x - o.x , y - o.y);
    }
    inline base operator * (const base &o) const {
        return base(x * o.x - y * o.y , x * o.y + y * o.x);
    }
    inline base operator / (const long double n) const {
        return base(x / n, y);
    }
    inline void operator += (const base &o){
        x += o.x, y += o.y;
    }
    inline void operator -= (const base &o){
        x -= o.x, y -= o.y;
    }
    inline void operator *= (const base &o){
        long double ax = x * o.x - y * o.y, ay = x * o.y + y * o.x;
        x = ax, y = ay;
    }
    inline void operator /= (const int n){
        x /= n;
    }
};
base root[30],iroot[30];
void init(){
    rep(i,1,30){
        long double ang=2*PI/(1<<i);
        root[i]=base(cos(ang),sin(ang));
        iroot[i]=base(cos(-ang),sin(-ang));
    }
}
void fft(base *a,bool invert,int n=(1<<19)){
    for(int i=1,j=0;i<n;++i){
        int bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit;
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2,pp=1;len<=n;len<<=1,pp++){
        base wlen=invert?iroot[pp]:root[pp];
        for(int i=0;i<n;i+=len){
            base w(1);
            rep(j,0,len/2){
                base u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }
    if(invert){
        for(int i=0;i<n;++i){
            a[i].x/=n;
        }
    }
}
#define N 1<<19
int p[27],t4[N],sp2[N],w[27];
string t,s;
base vt[N],vtt[N],vttt[N],vsplusp[N],vsp[N],v[N];
void solve(){
    init();
    rep(i,1,27){
        cin>>w[i];
        p[w[i]]=i;
    }
    cin>>t>>s;
    reverse(all(t));
    rep(i,0,sz(t)) vt[i]=t[i]-'a'+1;
    rep(i,0,sz(t)) vtt[i]=vt[i]*vt[i];
    rep(i,0,sz(t)) vttt[i]=vtt[i]*vt[i];
    rep(i,0,sz(s)) vsplusp[i]=s[i]-'a'+1+p[s[i]-'a'+1];
    rep(i,0,sz(s)) vsp[i]=(s[i]-'a'+1)*(p[s[i]-'a'+1]);
    rep(i,0,N) v[i]=vsplusp[i];
    fft(vttt,false);
    fft(v,false);
    rep(i,0,N) vttt[i]*=v[i];
    fft(vttt,true);
    rep(i,0,N) v[i]=(vsplusp[i]*vsplusp[i]+vsp[i]+vsp[i]);
    fft(vtt,false);
    fft(v,false);
    rep(i,0,N) vtt[i]*=v[i];
    fft(vtt,true);
    rep(i,0,N) v[i]=vsplusp[i]*vsp[i];
    fft(vt,false);
    fft(v,false);
    rep(i,0,N) vt[i]*=v[i];
    fft(vt,true);
    rep(i,1,sz(t)+1) t4[i]=t4[i-1]+(t[i-1]-'a'+1)*(t[i-1]-'a'+1)*(t[i-1]-'a'+1)*(t[i-1]-'a'+1);
    rep(i,1,sz(s)+1) sp2[i]=sp2[i-1]+(s[i-1]-'a'+1)*p[s[i-1]-'a'+1]*(s[i-1]-'a'+1)*p[s[i-1]-'a'+1];
    rep(i,sz(t)-1,sz(s)){
        int val=0;
        val+=t4[sz(t)];
        val-=2*(int)(vttt[i].x+0.5);
        val+=(int)(vtt[i].x+0.5);
        val-=2*(int)(vt[i].x+0.5);
        val+=sp2[i+1]-sp2[i-sz(t)+1];
        if(val==0) cout<<1;
        else cout<<0;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}