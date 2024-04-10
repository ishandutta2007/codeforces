#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const ll inf=1e18;
inline ll rnd()
{
    return(ll)rand()<<45|(ll)rand()<30|(ll)rand()<<15|rand();
}
ll n,i;
ll a[1000010];
ll m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(time(NULL));
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(int iter=0;iter<10;iter++)
    {
        int t=rnd()%n;
        ll at=a[t];
        vector<ll>v,p;
        for(i=1;i*i<=at;i++)
            if(at%i==0)
                v.eb(i),v.eb(at/i);
        sort(all(v));
        v.erase(unique(all(v)),v.end());
        for(i=1;i<v.size();i++)
        {
            int j;
            for(j=0;j<p.size();j++)
                if(v[i]%p[j]==0)
                    break;
            if(j>=p.size())
                p.eb(v[i]);
        }
        vector<ll>c(v.size(),0);
        for(i=0;i<n;i++)
            c[lower_bound(all(v),__gcd(a[i],at))-v.begin()]++;
        for(i=0;i<v.size();i++)
            for(int j=i+1;j<v.size();j++)
                if(v[j]%v[i]==0)
                    c[i]+=c[j];
        for(i=0;i<v.size();i++)
            if(c[i]*2>=n)
                m=max(m,v[i]);
    }
    cout<<m<<endl;
    return 0;
}