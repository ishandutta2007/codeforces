#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL INF=1e18;
LL N,i,j;
LL D[1234];
bool flag;
LL d;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>D[i];
    for(i=0;i<1<<N;i++)
    {
        d=0;
        for(j=0;j<N;j++)
        {
            if(i>>j&1)
                d+=D[j];
            else
                d-=D[j];
        }
        if(d%360==0)
        {
            flag=true;
            break;
        }
    }
    if(flag)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    return 0;
}