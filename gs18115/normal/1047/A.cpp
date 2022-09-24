#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int i,N;
    cin>>N;
    for(i=0;i<N;i++)
        if(i%3!=0&&(N-i*2)%3!=0)
            return cout<<i<<' '<<i<<' '<<N-i*2<<endl,0;
    return 0;
}