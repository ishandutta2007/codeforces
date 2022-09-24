#include<iostream>
#include<set>
using namespace std;
typedef long long LL;
const LL MAXI=1234567;
const LL INF=1LL<<55LL;
LL i,N;
LL a,b,c,d,e,f,g,h,s;
LL A[MAXI];
set<int>p,q,r;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>a;
        s+=a;
    }
    for(i=0;i<N;i++)
    {
        cin>>b;
        c+=b;
    }
    if(c>s)
        cout<<"No";
    else
        cout<<"Yes";
    return 0;
}