#include<iostream>
#include<set>
using namespace std;
typedef long long LL;
set<LL>S;
LL T,A;
LL N,K,i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    for(i=0;i<N;i++)
    {
        cin>>A;
        S.insert(A);
    }
    for(i=0;i<K;i++)
    {
        auto t=S.lower_bound(T+1);
        if(t==S.end())
        {
            cout<<0<<'\n';
            continue;
        }
        cout<<*t-T<<'\n';
        T=*t;
    }
    cout<<endl;
    return 0;
}