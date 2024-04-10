#include<iostream>
#include<vector>
#include<algorithm>
#define eb emplace_back
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL N,i;
vector<PL>Va,Vb;
LL A[1000010],B[1000010];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i]>>B[i];
        if(A[i]<B[i])
            Va.eb(A[i],i);
        else
            Vb.eb(A[i],i);
    }
    if(Va.size()>Vb.size())
    {
        sort(Va.begin(),Va.end(),greater<PL>());
        cout<<Va.size()<<endl;
        for(i=0;i<Va.size();i++)
            cout<<Va[i].se+1<<' ';
        cout<<endl;
    }
    else
    {
        sort(Vb.begin(),Vb.end());
        cout<<Vb.size()<<endl;
        for(i=0;i<Vb.size();i++)
            cout<<Vb[i].se+1<<' ';
        cout<<endl;
    }
    return 0;
}