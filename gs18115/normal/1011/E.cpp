#include<iostream>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
LL N,K,i,D,cnt,A;
bool chk[123456];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>K;
    D=0;
    for(i=0;i<N;i++)
    {
        cin>>A;
        D=gcd(A%K,D);
    }
    for(i=0;i<K;i++)
        chk[D*i%K]=true;
    for(i=0;i<K;i++)
        if(chk[i])
            cnt++;
    cout<<cnt<<endl;
    for(i=0;i<K;i++)
        if(chk[i])
            cout<<i<<' ';
    cout<<endl;
    return 0;
}