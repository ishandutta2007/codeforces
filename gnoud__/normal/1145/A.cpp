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
const int N=20;
int n,a[N],kq;
bool cheq(int l,int r)
{
    forinc(i,l+1,r) if(a[i]<a[i-1]) return 0;
    return 1;
}
void duyet(int l,int r)
{
    if(cheq(l,r)) kq=max(kq,r-l+1);
    else
    {
        int mid=(l+r)/2;
        duyet(l,mid);
        duyet(mid+1,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("THANOS.inp","r",stdin);
    cin>>n;
    forinc(i,1,n) cin>>a[i];
    duyet(1,n);
    cout<<kq;
}