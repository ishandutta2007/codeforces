#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,M,L,T,P,i;
LL A[1234567];
LL comp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M>>L;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        if(A[i]>L)
            comp++;
    }
    for(i=1;i<N;i++)
        if(A[i-1]>L&&A[i]>L)
            comp--;
    while(M--)
    {
        cin>>T;
        if(T==0)
            cout<<comp<<'\n';
        else
        {
            cin>>T>>P;
            if(A[--T]>L)
                continue;
            A[T]+=P;
            if(A[T]>L)
            {
                comp++;
                if(T!=0&&A[T-1]>L)
                    comp--;
                if(T!=N-1&&A[T+1]>L)
                    comp--;
            }
        }
    }
    cout<<endl;
    return 0;
}