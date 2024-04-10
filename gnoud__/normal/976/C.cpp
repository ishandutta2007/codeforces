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
const int N=3e5+10;
int n,mx[N][20],vt[N][20];
struct oo {int l,r,id;} a[N];
bool cmp(oo u,oo v)
{
    return (u.l<v.l||(u.l==v.l&&u.r>v.r));
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9') {x=x*10+c-'0';c=getchar();}
}
pii get(int i,int j)
{
    int tg=log2(j-i+1);
    if(mx[i][tg]<mx[j-(1<<tg)+1][tg]) return {mx[i][tg],vt[i][tg]};
    return {mx[j-(1<<tg)+1][tg],vt[j-(1<<tg)+1][tg]};
}
main()
{
    //freopen("a.inp","r",stdin);
    read(n);
    forinc(i,1,n) read2(a[i].l,a[i].r),a[i].id=i;
    sort(a+1,a+n+1,cmp);
    forinc(i,1,n)
    {
        mx[i][0]=a[i].r;
        vt[i][0]=a[i].id;
    }
    forinc(j,1,log2(n)) forinc(i,1,n) if(i+(1<<j)-1<=n)
    {
        if(mx[i][j-1]<mx[i+(1<<(j-1))][j-1])
        {
            mx[i][j]=mx[i][j-1];
            vt[i][j]=vt[i][j-1];
        }
        else
        {
            mx[i][j]=mx[i+(1<<(j-1))][j-1];
            vt[i][j]=vt[i+(1<<(j-1))][j-1];
        }
    }
    forinc(i,1,n-1)
    {
        int l=i+1,r=n,o=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[mid].l<=a[i].r) {o=mid;l=mid+1;}
            else r=mid-1;
        }
        if(o==-1) continue;
        pii tg=get(i+1,o);
        if(tg.fi<=a[i].r) {cout<<tg.se<<" "<<a[i].id;return 0;}
    }
    cout<<-1<<" "<<-1;
}