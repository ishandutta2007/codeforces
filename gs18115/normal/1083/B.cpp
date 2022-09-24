#include<iostream>
using namespace std;
char S[1234567],T[1234567];
long long N,K,P,cnt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>K;
    cin>>S;
    cin>>T;
    for(int i=0;i<N;i++)
    {
        P=P*2+T[i]-S[i];
        if(P>K*3+3)
            P=K*3+3;
        cnt+=min(P+1,K);
    }
    cout<<cnt<<endl;
    return 0;
}