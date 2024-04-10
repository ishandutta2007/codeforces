#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
#define forv(a,b) for(auto&a:b)
#define stop system("pause")
#define fi first
#define se second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define pp pop_back()
#define mp3(a,b,c) mp(a,mp(b,c))
#define mp4(a,b,c,d) mp(mp(a,b),mp(c,d))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define min4(a,b,c,d) min(min(a,d),min(b,c))
#define pii pair<int,int>
#define piii pair<int,pii >
#define pi4 pair<pair<int,int>,pair<int,int>>
#define all(a) a.begin(),a.end()
#define sz(s) int(s.size())
#define reset(f, x) memset(f, x, sizeof(f))
#define two(n) (1<<n)
#define bit(x,i) ((x>>(i-1))&1)
#define batbit(x,i) (x|(1ll<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
#define read4(a,b,c,d) read(a),read(b),read(c),read(d)
#define gcd(a,b) abs(__gcd(a,b))
#define lim 2139062143
#define getb(x) ((x-1)/T+1)
#define daub(x) T*(x-1)+1
#define cuoib(x) T*x
#define db double
using namespace std;
const int N=100010;
piii a[N];
pii _a[N];
int n,T,top[400],q,X[N];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
vector<piii> st[400];
double giao(piii u,piii v)
{
    return db(db(v.sf)-db(u.sf))/(db(u.fi)-db(v.fi));
}
bool cmp(piii u,piii v)
{
    return (u.sf<v.sf||(u.sf==v.sf&&u.fi<v.fi));
}
main()
{
    //freopen("91E.inp","r",stdin);
    //freopen("91E.out","w",stdout);
    read2(n,q);
    T=sqrt(n);
    forinc(i,1,n)
    {
        read2(a[i].fi,a[i].sf);
        a[i].ss=i;
        _a[i]={a[i].fi,a[i].sf};
    }
    for(int i=1;i<=n;i+=T)
    {
        vector<piii> e;
        sort(a+i,a+min(i+T,n+1),cmp);
        forinc(I,i,min(i+T-2,n-1))
        forinc(J,I+1,min(i+T-1,n)) if(a[I].fi<=a[J].fi) X[I]=1;
        forinc(I,i,min(i+T-1,n)) if(!X[I]) e.pb(a[I]);
        int b=getb(i);
        st[b].pb(mp3(e[0].sf,e[0].fi,e[0].ss));
        if(e.size()>1)
        {
            st[b].pb(mp3(e[1].sf,e[1].fi,e[1].ss));
            top[b]=1;
            forinc(j,2,e.size()-1)
            {
                while(top[b]>=1&&giao(st[b][top[b]-1],st[b][top[b]])>=giao(st[b][top[b]],mp3(e[j].sf,e[j].fi,e[j].ss)))
                {top[b]--;st[b].pp;}
                ++top[b];st[b].pb(mp3(e[j].sf,e[j].fi,e[j].ss));
            }
        }
        /*cout<<i<<" "<<b<<" "<<top[b]<<endl;
        forinc(j,0,top[b]) cout<<st[b][j].fi<<" "<<st[b][j].sf<<" "<<st[b][j].ss<<endl;
        cout<<endl;*/
    }
    forinc(Q,1,q)
    {
        int l,r,t;
        read3(l,r,t);
        int kq=0,B1=getb(l),B2=getb(r),_kq;
        if(B1==B2)
        {
            forinc(i,l,r) if(_a[i].se*t+_a[i].fi>kq)
            {
                kq=_a[i].se*t+_a[i].fi;
                _kq=i;
            }
        }
        else
        {
            forinc(i,l,cuoib(B1))
            if(_a[i].se*t+_a[i].fi>kq)
            {
                kq=_a[i].se*t+_a[i].fi;
                _kq=i;
            }
            forinc(i,daub(B2),r)
            if(_a[i].se*t+_a[i].fi>kq)
            {
                kq=_a[i].se*t+_a[i].fi;
                _kq=i;
            }
            forinc(i,B1+1,B2-1)
            {
                int l=1,r=top[i],o=0;
                while(l<=r)
                {
                    int mid=(l+r)/2;
                    if(giao(st[i][mid],st[i][mid-1])<t)
                    {
                        o=mid;
                        l=mid+1;
                    }
                    else r=mid-1;
                }
                if(st[i][o].fi*t+st[i][o].sf>kq)
                {
                    kq=st[i][o].fi*t+st[i][o].sf;
                    _kq=st[i][o].ss;
                }
            }
        }
        //cout<<_a[28].se*t+_a[28].fi<<endl;
        //cout<<_a[_kq].se*t+_a[_kq].fi<<endl;
        cout<<_kq<<"\n";
    }
}