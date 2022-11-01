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
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int kq=0;
        int n;cin>>n;
        forinc(T,0,8)
        {
            vector<int> a,b;
            forinc(i,1,n) if((i>>T)&1) a.pb(i);else b.pb(i);
            if(a.empty()||b.empty()) continue;
            cout<<a.size()<<" "<<b.size()<<" ";
            forv(x,a) cout<<x<<" ";
            forv(x,b) cout<<x<<" ";
            cout<<"\n";
            int ma;cin>>ma;
            kq=max(kq,ma);
        }
        cout<<-1<<" "<<kq<<"\n";
    }
}