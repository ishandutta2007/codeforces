#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define int long long
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
const int N=2010;
int m,n,x,a[N],b[N],c[N][N],s[N][N],o[N],kq;
int sum(int x,int y,int u,int v)
{
    return s[u][v]-s[u][y-1]-s[x-1][v]+s[x-1][y-1];
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("C.inp","r",stdin);
    //freopen("C.out","w",stdout);
    cin>>m>>n;
    forinc(i,1,m) cin>>a[i];
    forinc(i,1,n) cin>>b[i];
    cin>>x;
    forinc(i,1,m) forinc(j,1,n)
    {
        c[i][j]=a[i]*b[j];
        s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+c[i][j];
    }
    forinc(l,1,m) forinc(i,1,m-l+1) if(o[l]==0||sum(i,1,i+l-1,1)<sum(o[l],1,o[l]+l-1,1)) o[l]=i;
    forinc(i,1,n) forinc(L,1,m)
    {
        int vt=o[L];
        int l=i,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(sum(vt,i,vt+L-1,mid)<=x) {kq=max(kq,L*(mid-i+1));l=mid+1;}
            else r=mid-1;
        }
    }
    cout<<kq;
}