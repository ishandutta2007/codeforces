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
const int N=200010;
int mx[N][30],a[N],th[4*N],mem[4*N],dd[N],dc[N];
void read(int & x)
{
    x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
}
int get(int x,int y)
{
    int tg=log2(y-x+1);
    return min(mx[x][tg],mx[y-(1<<tg)+1][tg]);
}
void tran(int s)
{
    if(!mem[s])return ;
    th[2*s]=mem[s];
    mem[2*s]=mem[s];
    th[2*s+1]=mem[s];
    mem[2*s+1]=mem[s];
    mem[s]=0;
}
void update(int s,int l,int r,int u,int v,int x)
{
    int mid=(l+r)/2;
    if(v<l||r<u)return ;
    if(u<=l&&r<=v)
    {
        th[s]=x;
        mem[s]=x;
        return;
    }
    tran(s);
    update(2*s,l,mid,u,v,x);
    update(2*s+1,mid+1,r,u,v,x);
    th[s]=max(th[2*s],th[2*s+1]);
}
int get1(int s,int l,int r,int u,int v)
{
    int mid=(l+r)/2;
    if(v<l||r<u) return 0;
    if(u<=l&&r<=v)
    {

        return th[s];
    }
    tran(s);
    return max(get1(2*s,l,mid,u,v),get1(2*s+1,mid+1,r,u,v));
}
int main()
{
    //freopen("bai1.inp","r",stdin);
    int n,q;int O=-1;
    read(n);read(q);bool ok=0;
    forinc(i,1,n) {read(a[i]);if(a[i]!=0) ok=true;if(a[i]==0) O=i;;dc[a[i]]=1;}
    if(!dc[q])
    {
        if(O==-1) {cout<<"NO";return 0;}
        a[O]=q;
    }
    if(!ok)
    {
        cout<<"YES\n";
        forinc(i,1,n) cout<<q<<" ";
        return 0;
    }
    forinc(i,1,n) if(a[i]==0) a[i]=a[i-1];
    fordec(i,n,1) if(a[i]==0) a[i]=a[i+1];
    forinc(i,1,n) mx[i][0]=a[i];
    forinc(j,1,log2(n))
    forinc(i,1,n) if(i+(1<<(j))-1<=n) mx[i][j]=min(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
    int ht=1;
    while(ht<=n)
    {
        if(dd[a[ht]])
        {
            if(ht>dd[a[ht]])
            {cout<<"NO";return 0;}
            else {ht++;continue;}
        }
        int l=ht,r=n,o=ht;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(get(ht,mid)==a[ht]) {o=mid;l=mid+1;}
            else r=mid-1;
        }
        update(1,1,n,ht,o,a[ht]);
        dd[a[ht]]=o;ht++;
    }
    cout<<"YES\n";
    forinc(i,1,n) cout<<get1(1,1,n,i,i)<<" ";
}