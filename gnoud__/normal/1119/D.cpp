#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
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
const int N=100010;
int n,q,a[N],s[N],e[N];
main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    forinc(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    forinc(i,1,n-1) e[i]=a[i+1]-a[i];
    sort(e+1,e+n);
    forinc(i,1,n-1) s[i]=s[i-1]+e[i];
    cin>>q;
    while(q--)
    {
        int l,r,c;
        cin>>l>>r;
        c=r-l+1;
        int i=upper_bound(e+1,e+n,c)-e-1;
        cout<<c*(n-i)+s[i]<<" ";
    }
}