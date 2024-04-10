#include<iostream>
using namespace std;
long long N,K,P,ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    if(N>K-2)
    {
        if(K&1LL==1LL)
            ans=(K>>1LL);
        else
            ans=(K>>1LL)-1LL;
    }
    else
    {
        P=K-N;
        if(K&1LL==1LL)
            ans=(K>>1LL)-P+1LL;
        else
            ans=(K>>1LL)-P;
    }
    cout<<(ans<0?0:ans)<<endl;
    return 0;
}