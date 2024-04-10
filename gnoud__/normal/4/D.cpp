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
const int N=5010;
int n,f[N],w,h,kq,trc[N];
struct oo {int w,h,id;};
bool cmp(oo u,oo v) {return u.w<v.w;}
oo a[N];
vector<int> ans;
main()
{
    //freopen("B.inp","r",stdin);
    cin>>n>>w>>h;
    forinc(i,1,n) {cin>>a[i].w>>a[i].h;a[i].id=i;}
    sort(a+1,a+n+1,cmp);
    forinc(i,1,n)
    {
        if(a[i].h<=h||a[i].w<=w) continue;
        f[i]=1;
        forinc(j,1,i-1) if(a[i].h>a[j].h&&a[i].w>a[j].w&&f[i]<f[j]+1)
        {
            f[i]=f[j]+1;
            trc[i]=j;
        }
        if(f[i]>f[kq]) kq=i;
    }
    cout<<f[kq]<<"\n";
    while(kq) {ans.pb(a[kq].id);kq=trc[kq];}
    reverse(all(ans));
    forv(x,ans) cout<<x<<" ";
}