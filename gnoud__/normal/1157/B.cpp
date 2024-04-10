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
int n,f[10],a[200010];
int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("B.inp","r",stdin);
    cin>>n;
    forinc(i,1,n)
    {
        char c;cin>>c;
        a[i]=c-'0';
    }
    forinc(i,1,9) cin>>f[i];
    int l=1;
    while(l<=n&&a[l]>=f[a[l]]) ++l;
    while(l<=n&&a[l]<=f[a[l]]) a[l]=f[a[l]],++l;
    forinc(i,1,n) cout<<a[i];
}