#include<iostream>
using namespace std;
int i,N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    if(N==1||N==2)
        return cout<<"No"<<endl,0;
    cout<<"Yes"<<endl<<"1 "<<N<<endl<<N-1<<' ';
    for(i=1;i<N;i++)
        cout<<i<<' ';
    cout<<endl;
    return 0;
}