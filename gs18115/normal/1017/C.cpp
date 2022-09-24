#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
LL i,j,X,Y,N;
pair<LL,LL>P[123456];
bool cmp(pair<LL,LL>A,pair<LL,LL>B)
{
    return A.second<B.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(X=1;X*X<N;X++);
    for(i=0;i<N;i+=X)
    {
        Y=N-(i+1)/X*X;
        for(j=0;j<X&&i+j<N;j++)
        {
            P[i+j].first=Y+j;
            P[i+j].second=i+j;
        }
    }
    sort(P,P+N);
    for(i=0;i<N;i++)
        P[i].first=i+1;
    sort(P,P+N,cmp);
    for(i=0;i<N;i++)
        cout<<P[i].first<<' ';
    return 0;
}