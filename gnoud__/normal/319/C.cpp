#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
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
#define int long long
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
#define db double
using namespace std;
const int N=100010;
int n,a[N],b[N],top;
int f[N];
void read(int & x)
{
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
}
vector<pair<int,int >> st;
double giao(pii u,pii v)
{
    return db(db(v.se)-db(u.se))/(db(u.fi)-db(v.fi));
}
main()
{
    //freopen("319C.inp","r",stdin);
    read(n);
    forinc(i,1,n) read(a[i]);
    forinc(i,1,n) read(b[i]);
    f[1]=0;st.pb({b[1],0});
    forinc(i,2,n)
    {
        int l=1,r=top,o=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(giao(st[mid],st[mid-1])<a[i])
            {
                o=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        f[i]=a[i]*st[o].fi+st[o].se;
        pii O={b[i],f[i]};
        while(top>=1&&giao(st[top-1],st[top])>=giao(st[top],O)) {top--;st.pp;}
        ++top;st.pb(O);
    }
    cout<<f[n];
}