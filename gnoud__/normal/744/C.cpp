#include<bits/stdc++.h>
using namespace std;
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
const int N=17;
int f[1<<N][N*N],n,a[N],b[N],A[N],B[N],kq=1e9,Sa,Sb;
int main()
{
    //freopen("744C.inp","r",stdin);
    cin>>n;
    forinc(i,1,n)
    {
        char x;
        cin>>x>>A[i]>>B[i];
        Sa+=A[i],Sb+=B[i];
        if(x=='R') a[i]++;
        else b[i]++;
    }
    int lim=(1<<n)-1;
    reset(f,-1);
    f[0][0]=0;
    forinc(tt,0,lim-1) forinc(ra,0,n*n) if(f[tt][ra]!=-1)
    {
        int rb=f[tt][ra];
        int sa=0,sb=0;
        forinc(i,1,n) if(bit(tt,i)) sa+=a[i],sb+=b[i];
        forinc(i,1,n) if(!bit(tt,i))
        {
            int tt2=onbit(tt,i);
            int _ra=ra+min(A[i],sa);
            f[tt2][_ra]=max(f[tt2][_ra],rb+min(B[i],sb));
        }
    }
    forinc(ra,0,n*n) if(f[lim][ra]!=-1)
    {
        int rb=f[lim][ra];
        kq=min(kq,max(Sa-ra,Sb-rb));
    }
    cout<<kq+n;
}