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
const int N=1e6+10;
int n,m,a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    forinc(i,1,n)
    {
        int x;cin>>x;
        a[x%2]++;
    }
    forinc(i,1,m)
    {
        int x;cin>>x;
        b[x%2]++;
    }
    cout<<min(a[0],b[1])+min(a[1],b[0]);
}