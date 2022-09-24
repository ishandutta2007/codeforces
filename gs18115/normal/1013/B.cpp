#include<iostream>
#include<set>
using namespace std;
typedef long long LL;
const LL MAXI=1234567;
const LL INF=1LL<<55LL;
LL i,N;
LL a,b,c,d,e,f,g,h,s;
LL A[MAXI];
set<int>p,q,r,o;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>b;
    for(i=0;i<N;i++)
    {
        cin>>a;
        A[i]=a;
        if(p.find(a)!=p.end())
        {
            cout<<0;
            return 0;
        }
        p.insert(a);
    }
    for(i=0;i<N;i++)
    {
        if(q.find(A[i])!=q.end())
        {
            cout<<1;
            return 0;
        }
        q.insert(A[i]&b);
    }
    for(i=0;i<N;i++)
    {
        if(r.find(A[i]&b)!=r.end())
        {
            cout<<1;
            return 0;
        }
        r.insert(A[i]);
    }
    for(i=0;i<N;i++)
    {
        if(o.find(A[i]&b)!=o.end())
        {
            cout<<2;
            return 0;
        }
        o.insert(A[i]&b);
    }
    cout<<-1;
    return 0;
}