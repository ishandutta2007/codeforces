#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const LL MOD=1e9+7;
multiset<LL>SET;
LL N,X,Y,bnd;
LL i,S,P;
PL seg[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>X>>Y;
    bnd=X/Y;
    for(i=0;i<N;i++)
        cin>>seg[i].first>>seg[i].second;
    sort(seg,seg+N);
    for(i=0;i<N;i++)
    {
        set<LL>::iterator it=SET.lower_bound(seg[i].first);
        if(it==SET.begin())
            S+=(seg[i].second-seg[i].first)*Y+X;
        else
        {
            P=*--it;
            SET.erase(it);
            if(seg[i].first-P<=bnd)
                S+=(seg[i].second-P)*Y;
            else
                S+=(seg[i].second-seg[i].first)*Y+X;
        }
        SET.insert(seg[i].second);
        S%=MOD;
    }
    cout<<S%MOD<<endl;
    return 0;
}