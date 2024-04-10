#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>>N;
    int maxi=-2e9,mini=2e9;
    for(int i=0;i<N;i++)
    {
        int A;
        cin>>A;
        maxi=max(maxi,A);
        mini=min(mini,A);
    }
    cout<<maxi-mini+1-N<<endl;
    return 0;
}