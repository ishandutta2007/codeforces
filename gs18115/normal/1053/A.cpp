#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
LL N,M,K,L;
LL i,j;
vector<LL>V1,V2;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>K;
    if(N*M*2%K!=0)
        return cout<<"NO"<<endl,0;
    for(i=1;i*i<N;i++)
    {
        if(N%i==0)
        {
            V1.push_back(i);
            V1.push_back(N/i);
        }
    }
    if(i*i==N)
        V1.push_back(i);
    sort(V1.begin(),V1.end());
    for(i=1;i*i<M;i++)
    {
        if(M%i==0)
        {
            V2.push_back(i);
            V2.push_back(M/i);
        }
    }
    if(i*i==M)
        V2.push_back(i);
    sort(V2.begin(),V2.end());
    L=N*M*2/K;
    for(i=0;i<V1.size();i++)
    {
        if(L%V1[i]!=0)
            continue;
        for(j=0;j<V2.size();j++)
        {
            if(L%(V1[i]*V2[j])==0)
            {
                LL I=V1[i]*V2[j];
                if(I<=N&&L/I<=M)
                    return cout<<"YES\n0 0\n0 "<<L/I<<'\n'<<I<<" 0"<<endl,0;
                else if(I<=M&&L/I<=N)
                    return cout<<"YES\n0 0\n0 "<<I<<'\n'<<L/I<<" 0"<<endl,0;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}