#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
vector<LL>V,V2;
LL N,x,n,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=1;i*i<=N;i++)
    {
        if(N%i==0)
        {
            V.push_back(i);
            V.push_back(N/i);
        }
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    for(i=0;i<V.size();i++)
    {
        x=V[i];
        n=N/x;
        V2.push_back(((n-1)*x+2)*n>>1);
    }
    sort(V2.begin(),V2.end());
    for(i=0;i<V2.size();i++)
        cout<<V2[i]<<' ';
    cout<<endl;
    return 0;
}