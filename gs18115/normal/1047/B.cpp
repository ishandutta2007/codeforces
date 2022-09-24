#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,x,y,i,maxi=-1;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>x>>y;
        maxi=max(maxi,x+y);
    }
    cout<<maxi<<endl;
    return 0;
}