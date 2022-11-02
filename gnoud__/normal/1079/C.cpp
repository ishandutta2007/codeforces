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
const int N=100010;
int f[N][6],n,a[N],trc[N][6];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    //freopen("a.inp","r",stdin);
    read(n);
    forinc(i,1,n) read(a[i]);
    forinc(i,1,5) f[1][i]=1;
    forinc(i,1,n-1) forinc(j,1,5) if(f[i][j])
    {
        if(a[i]<a[i+1]) forinc(t,j+1,5) {f[i+1][t]=1;trc[i+1][t]=j;}
        if(a[i]>a[i+1]) forinc(t,1,j-1) {f[i+1][t]=1;trc[i+1][t]=j;}
        if(a[i]==a[i+1]) forinc(t,1,5) if(t!=j) {f[i+1][t]=1;trc[i+1][t]=j;}
    }
    forinc(i,1,5) if(f[n][i])
    {
        vector<int> kq;
        int I=n,J=i;
        while(I)
        {
            kq.pb(J);
            J=trc[I][J];I--;
        }
        reverse(all(kq));
        forv(x,kq) cout<<x<<" ";
        return 0;
    }
    cout<<-1;
    return 0;
}