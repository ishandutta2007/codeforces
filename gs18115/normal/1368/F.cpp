#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18+7;
inline int query(vector<int>v)
{
    if(v.empty())
        return 1;
    cout<<v.size();
    for(int&t:v)
        cout<<' '<<t;
    cout<<endl;
    int x;
    cin>>x;
    return x;
}
bool on[1010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int mi=2;
    for(int k=1;k++<n;)
        if((n+k-1)/k+k<(n+mi-1)/mi+mi)
            mi=k;
    vector<int>vq;
    for(int i=0;i<n;i+=mi)
        for(int j=1;j<mi&&i+j<n;j++)
            vq.eb(i+j);
    while(1)
    {
        vector<int>qv;
        int k=0;
        for(int&t:vq)
            if(!on[t])
                qv.eb(t),on[t]=1,k++;
        int q=query(qv);
        bool f=1;
        for(int i=0;i<k;i++)
        {
            int j=(q-1+i)%n+1;
            if(!on[j])
                f=0;
            else
                on[j]=0;
        }
        if(f)
            break;
    }
    cout<<0<<endl;
    return 0;
}