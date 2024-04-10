#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
const int N=210;
int m,n,a[N][N],h[N],c[N],b[N][N];
bool bd()
{
    forinc(i,1,n) if(a[1][i]^h[1]!=b[1][i]) c[i]=1;
    forinc(i,1,m) if(a[i][1]^c[1]!=b[i][1]) h[i]=1;
    int o=0;
    forinc(i,1,m) forinc(j,1,n)
    {
        int oo=a[i][j]^h[i]^c[j];
        if(o&&oo!=o) return 0;
        o=oo;
    }
    return 1;
}
void inkq()
{
    cout<<"YES\n";
    forinc(i,1,m) cout<<h[i];cout<<"\n";
    forinc(i,1,n) cout<<c[i];cout<<"\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("G.inp","r",stdin);
    cin>>m>>n;
    forinc(i,1,m) forinc(j,1,n) cin>>a[i][j];
    forinc(t,1,m)
    {
        forinc(o,0,n*(t==1))
        {
            if(t>1) o=n+1;
            forinc(i,1,m) forinc(j,1,n)
            {
                if(i==1&&j<=o) b[i][j]=0;
                else b[i][j]=1;
                if(i<=t) b[i][1]=0;
            }
            reset(h,0);reset(c,0);
            if(bd()) inkq();
            reset(h,0);reset(c,0);
            h[1]=1;
            if(bd()) inkq();
        }
    }
    cout<<"NO";
}