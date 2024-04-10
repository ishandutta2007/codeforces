#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
const int N=300010;
int n,a[N],s[N],t[N][2];
vector<int> e;
int v(int x) {return lower_bound(all(e),x)-e.begin()+1;}
int S(int l,int r)
{
    return s[r]^s[l-1];
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("a.inp","r",stdin);
    cin>>n;
    forinc(i,1,n)
    {
        cin>>a[i],s[i]=s[i-1]^a[i];
        e.pb(s[i]);
    }
    e.pb(0);
    sort(all(e));
    ll kq=0;
    t[v(0)][0]++;
    forinc(i,1,n)
    {
        kq+=t[v(s[i])][i%2];
        t[v(s[i])][i%2]++;
    }
    cout<<kq;
}