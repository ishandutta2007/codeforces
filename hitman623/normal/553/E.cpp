#include <bits/stdc++.h>

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
#define factor      100000
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define PI          3.141592653589793l
using namespace std;
struct base{
    double x , y;
    base(){
        x = 0;
        y = 0;
    }
    base(double _x){
        x = _x;
        y = 0;
    }
    base(double _x , double _y){
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
    inline base operator / (const double n) const {
        return base(x / n, y);
    }
    inline void operator += (const base &o){
        x += o.x, y += o.y;
    }
    inline void operator -= (const base &o){
        x -= o.x, y -= o.y;
    }
    inline void operator *= (const base &o){
        double ax = x * o.x - y * o.y, ay = x * o.y + y * o.x;
        x = ax, y = ay;
    }
    inline void operator /= (const int n){
        x /= n;
    }
};
base p1[100005],p2[100005],p3[100005]; 
const int R = 30;
base root[R], iroot[R];
void init(){
    rep(i,1,R){
        double ang=2*PI/(1<<i);
        root[i]=base(cos(ang),sin(ang));
        iroot[i]=base(cos(-ang),sin(-ang));
    }
}
void fft(base *a,bool invert,int n){
    for(int i=1,j=0;i<n;++i){
        int bit=n>>1;
        for(;j>=bit;bit>>=1){
            j-=bit;
        }
        j+=bit;
        if(i<j){
            swap(a[i],a[j]);
        }
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
            a[i]/=n;
        }
    }
}

int p[102][40004];
int presum[102][40004];
vii adj[52];
int w[52][52];
double we[102][40004];
double c[102][40004];
double wv[52][40004];
vii edges;

void multiply(int x,int n,int e){
    if(n<=16){
        int y=edges[e].y;
        rep(i,0,n){
            rep(j,0,n){
                c[e][i+x+j+1]+=wv[y][i+x-n]*p[e][j+n+1];
            }
        }
    }
    else{
        fill(p1+n,p1+n+n,0);
        fill(p2+n,p2+n+n,0);
        fill(p3,p3+n+n,0);
        rep(k,0,n){
            p1[k]=wv[edges[e].y][k+x-n];
            p2[k]=p[e][k+n+1];
        }
        n<<=1;
        fft(p1,false,n);
        fft(p2,false,n);
        rep(k,0,n) p3[k]=p1[k]*p2[k];
        fft(p3,true,n);
        rep(k,0,n) c[e][x+1+k]+=p3[k].x;    
    }
}

int n,m,t,x;
vi weight;
void solve(){
    init();
    cin>>n>>m>>t>>x;
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(i==j) w[i][j]=0;
            else w[i][j]=1e9;
        }
    }
    rep(i,0,n+1){
        rep(k,0,t+1){
            wv[i][k]=1e9;
        }
    }
    rep(i,0,m){
        int a,b,d;
        cin>>a>>b>>d;
        w[a][b]=d;
        adj[a].pb({b,i});
        edges.pb({a,b});
        weight.pb(d);
        rep(j,1,t+1){
            cin>>p[i][j];
            presum[i][j]=p[i][j]+presum[i][j-1];
        }
    }
    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                w[i][j]=min(w[i][k]+w[k][j],w[i][j]);
            }
        }
    }
    rep(i,1,n+1){
        wv[i][0]=w[i][n]+x;
    }
    wv[n][0]=0;
    rep(i,0,t+1){
        rep(j,0,m){
            c[j][i+1]+=wv[edges[j].y][i]*p[j][1];
            c[j][i+2]+=wv[edges[j].y][i]*p[j][2];
        }
        rep(j,1,n){
            wv[j][i+1]=w[j][n]+x;
        }
        wv[n][i+1]=0;
        rep(e,0,m){
            int j=2;
            while(i and i%j==0){
                multiply(i,j,e);
                j<<=1;
            }
            we[e][i+1]=c[e][i+1]+1LL*(presum[e][t]-presum[e][i+1])*(w[edges[e].y][n]+x);
            we[e][i+1]/=factor;
            we[e][i+1]+=weight[e];
        }
        rep(j,1,n){
            for(auto k:adj[j]){
                wv[j][i+1]=min(wv[j][i+1],we[k.y][i+1]);
            }
        }
    }
    cout<<wv[1][t]<<endl;
}

signed main(){
    cout<<fixed<<setprecision(6);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}