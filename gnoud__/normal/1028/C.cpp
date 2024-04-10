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
const int N=150000;
int n,mx[N],my[N],mu[N],mv[N];
int _mx[N],_my[N],_mu[N],_mv[N];
struct oo {int x,y,u,v;};
oo a[N];
void read( int &x)
{
    x = 0; char c; bool nega = 0;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') c = getchar(), nega = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (nega) x = -x;
}
bool cmp(oo u,oo v) {return u.x<v.x;}
void ktao()
{
    mx[0]=_mx[n+1]=-1e9;
    my[0]=_my[n+1]=-1e9;
    mu[0]=_mu[n+1]=1e9;
    mv[0]=_mv[n+1]=1e9;
    forinc(i,1,n)
    {
        mx[i]=max(a[i].x,mx[i-1]);
        my[i]=max(a[i].y,my[i-1]);
        mu[i]=min(a[i].u,mu[i-1]);
        mv[i]=min(a[i].v,mv[i-1]);
    }
    fordec(i,n,1)
    {
        _mx[i]=max(a[i].x,_mx[i+1]);
        _my[i]=max(a[i].y,_my[i+1]);
        _mu[i]=min(a[i].u,_mu[i+1]);
        _mv[i]=min(a[i].v,_mv[i+1]);
    }
}
int main()
{
    //freopen("Rectangles.inp","r",stdin);
    read(n);
    forinc(i,1,n)
    {
        int x,y,u,v;
        read4(x,y,u,v);
        a[i]={x,y,u,v};
    }
    sort(a+1,a+n+1,cmp);
    ktao();
    forinc(i,1,n)
    {
        int x=max(mx[i-1],_mx[i+1]);
        int y=max(my[i-1],_my[i+1]);
        int u=min(mu[i-1],_mu[i+1]);
        int v=min(mv[i-1],_mv[i+1]);
        if(x>u||y>v) continue;
        cout<<x<<" "<<y<<"\n";return 0;
    }
}