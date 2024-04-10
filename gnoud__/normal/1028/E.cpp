#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define int long long
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
using namespace std;
const int N=200010;
int n,b[N],a[N];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int so(int lim,int p,int r)
{
    return (lim/p+1)*p+r;
}
main()
{
    //freopen("1028E.inp","r",stdin);
    read(n);
    int ok=0,s=0;
    forinc(i,1,n)
    {
        read(b[i]);
        if(b[i]) ok=1;
    }
    b[n+1]=b[1];
    forinc(i,2,n) if(b[i]>b[i-1]) s=i;
    if(b[1]>b[n]) s=1;
    if(!s)
    {
        if(ok) return cout<<"NO\n",0;
        cout<<"YES\n";
        forinc(i,1,n) cout<<1<<" ";return 0;
    }
    a[s]=b[s];
    fordec(i,s-1,s-n+1)
    {
        int j=(i>0)?i:i+n;
        int _j=(j==1)?n:j-1;
        int __j=(j==n)?1:j+1;
        a[j]=so(b[_j],a[__j],b[j]);
    }
    cout<<"YES\n";
    forinc(i,1,n) cout<<a[i]<<" ";
}