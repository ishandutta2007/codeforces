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
using namespace std;
const int N=200010;
int n,a[N],t[N],k,sl,kq;
void update(int i,int x)
{
     for(;i<=n;i+=i&-i) t[i]+=x;
}
int get(int i)
{
    int g=0;
    for(;i;i-=i&-i) g+=t[i];
    return g;
}
main()
{
    //freopen("a.inp","r",stdin);
    cin>>n>>k;
    int pp=n;
    forinc(i,1,n) {cin>>a[i];sl+=a[i];update(i,a[i]);}
    forinc(ppp,1,n)
    {
        kq+=(k/sl)*pp;
        k%=sl;
        int l=1,r=n,o=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(get(mid)>k) o=mid,r=mid-1;
            else l=mid+1;
        }
        update(o,-a[o]);
        pp--;
        sl=get(n);
    }
    cout<<kq;
}