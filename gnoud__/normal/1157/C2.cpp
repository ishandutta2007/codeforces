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
const int N=2e5+10;
int n,a[N];
vector<char> ans;
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
void add(int l,int r)
{
    int L=l,R=r;
    while(L<r&&a[L+1]>a[L]) ++L;
    while(R>l&&a[R-1]>a[R]) --R;
    if(L-l>r-R) forinc(i,1,L-l+1) ans.pb('L');
    else forinc(i,1,r-R+1) ans.pb('R');
}
int main()
{
    //freopen("C2.inp","r",stdin);
    read(n);
    forinc(i,1,n) read(a[i]);
    int l=1,r=n,pre=0;
    while(l<=r)
    {
        if(a[l]==a[r])
        {
            if(a[l]>pre) add(l,r);
            break;
        }
        if(max(a[l],a[r])>pre)
        {
            if(a[l]<=pre) ans.pb('R'),pre=a[r--];
            else if(a[r]<=pre) ans.pb('L'),pre=a[l++];
            else if(a[l]>a[r]) ans.pb('R'),pre=a[r--];
            else ans.pb('L'),pre=a[l++];
        }
        else break;
    }
    cout<<ans.size()<<"\n";
    forv(x,ans) cout<<x;
}