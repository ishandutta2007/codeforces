#include<iostream>
using namespace std;
int N,M,i,K,S,maxi;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    cin>>M;
    for(i=0;i<N;i++)
    {
        cin>>K;
        maxi=max(K,maxi);
        S+=K;
    }
    cout<<max(maxi,(M+S+N-1)/N)<<' '<<maxi+M<<endl;
    return 0;
}