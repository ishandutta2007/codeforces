#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
LL Q,N,n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>Q;
    while(Q-->0)
    {
        cin>>N;
        for(n=1;n<=N;n<<=1);
        if(N+1!=n)
            cout<<n-1<<'\n';
        else
        {
            for(n=2;n*n<=N;n++)
                if(N%n==0)
                    break;
            if(n*n>N)
                n=N;
            cout<<N/n<<'\n';
        }
    }
    cout<<endl;
    return 0;
}