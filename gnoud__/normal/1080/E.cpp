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
const int N=260;
int m,n,mx[N][10],g[N][26],sl[N],L[N];
char a[N][N];
int kq;
ull o[N],A[N],B[N],pw[N],P[N];
ull get(int l,int r)
{
    return A[r]-A[l-1]*pw[r-l+1];
}
ull Get(int l,int r)
{
    return B[l]-B[r+1]*pw[r-l+1];
}
ull GET(int l,int r)
{
    int tg=L[r-l+1];
    return max(mx[l][tg],mx[r-(1<<tg)+1][tg]);
}
main()
{
    ios_base::sync_with_stdio(0);
    //freopen("a.inp","r",stdin);
    cin>>m>>n;
    pw[0]=1;P[0]=1;
    forinc(i,1,250) {pw[i]=pw[i-1]*257;L[i]=log2(i);}
    forinc(i,1,25) P[i]=P[i-1]*267;
    forinc(i,1,m) forinc(j,1,n) cin>>a[i][j];
    forinc(l,1,n) forinc(r,l,n)
    {
        if(l==r) {reset(o,0);reset(g,0);reset(sl,0);}
        forinc(i,1,m)
        {
            int x=a[i][r]-'a';
            g[i][x]++;
            if(g[i][x]%2) sl[i]++;
            else sl[i]--;
            if(sl[i]>1) mx[i][0]=1;
            else mx[i][0]=0;
            o[i]=o[i]+P[x]*x;
        }
        forinc(j,1,log2(m)) forinc(i,1,m) mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        forinc(i,1,m) A[i]=A[i-1]*257+o[i];
        fordec(i,m,1) B[i]=B[i+1]*257+o[i];
        forinc(i,1,m) if(!mx[i][0])
        {
            int l=i,r=min(m,i+(i-1)),tg=i;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(get(i,mid)==Get(2*i-mid,i)&&!GET(i,mid)) {tg=mid;l=mid+1;}
                else r=mid-1;
            }
            kq+=(tg-i+1);
        }
        forinc(i,2,m) if(!mx[i][0]&&!mx[i-1][0]&&o[i]==o[i-1])
        {
            int l=i,r=min(m,i+(i-2)),tg=i;
            while(l<=r)
            {
                int mid=(l+r)/2;
                if(get(i,mid)==Get(2*i-1-mid,i-1)&&!GET(i,mid)) {tg=mid;l=mid+1;}
                else r=mid-1;
            }
            kq+=(tg-i+1);
        }
    }
    cout<<kq;
}