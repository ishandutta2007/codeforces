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
const int N=110;
int n,m,a[N],h[N],dd[N],id[N],fre[N];
bool cheq(int i,int s)
{
    reset(fre,0);
    if(i<s)
    {
        int H=h[i];
        forinc(j,i+1,s) if(!h[j]&&!dd[j])
        {
            H+=a[j];
            fre[j]=1;
            if(H<0) return 0;
        }
    }
    else
    {
        int H=h[i];
        fordec(j,i-1,s) if(!h[j]&&!dd[j])
        {
            H+=a[j];
            fre[j]=1;
            if(H<0) return 0;
        }
    }
    forinc(i,1,n) if(fre[i]) dd[i]=1;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("a.inp","r",stdin);
    cin>>n>>m;
    forinc(i,1,m)
    {
        int s,H;
        cin>>s>>H;
        h[s]=H;id[s]=i;
    }
    forinc(i,1,n) cin>>a[i];
    forinc(s,1,n)
    {
        vector<int> kq;
        reset(dd,0);
        if(h[s]) kq.pb(id[s]);
        while(1)
        {
            bool ok=0;
            forinc(i,1,s-1) if(h[i]&&!dd[i]&&cheq(i,s))
            {dd[i]=1;ok=1;kq.pb(id[i]);}
            if(!ok) break;
        }
        bool O=0;
        forinc(i,1,s-1) if(h[i]&&!dd[i]) {O=1;continue;}
        if(O) continue;
        while(1)
        {
            bool ok=0;
            forinc(i,s+1,n) if(h[i]&&!dd[i]&&cheq(i,s))
            {dd[i]=1;ok=1;kq.pb(id[i]);}
            if(!ok) break;
        }
        forinc(i,s+1,n) if(h[i]&&!dd[i]) {O=1;continue;}
        if(O) continue;
        cout<<s<<"\n";
        forv(x,kq) cout<<x<<" ";
        return 0;
    }
    cout<<-1;
}