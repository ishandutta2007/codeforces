#include<iostream>
using namespace std;
typedef long long LL;
LL i,N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    if(N==1)
        return cout<<-1<<endl,0;
    cout<<N<<' '<<N<<endl;
    return 0;
}