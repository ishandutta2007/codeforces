#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define int long long
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
int n,k,a[N];
priority_queue<int> heap;
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("D.inp","r",stdin);
    //freopen("D.out","w",stdout);
    cin>>n>>k;
    int S=0;
    forinc(i,1,k)
    {
        a[i]=i;
        S+=a[i];
        if(S>n) return cout<<"NO",0;
    }
    forinc(i,1,k) a[i]+=(n-S)/k;
    n=(n-S)%k;
    forinc(i,1,k) heap.push(i);
    while(n)
    {
        if(heap.empty()) return cout<<"NO",0;
        int i=heap.top();heap.pop();
        if(a[i]<2*a[i-1]&&i<=k)
        {
            n--;
            a[i]++;
            heap.push(i+1);
        }
    }
    cout<<"YES\n";
    forinc(i,1,k) cout<<a[i]<<" ";
}