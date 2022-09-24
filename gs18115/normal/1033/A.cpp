#include<iostream>
using namespace std;
long long N,A,B,C,D,E,F;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>A>>B>>C>>D>>E>>F;
    if((A-C)*(A-E)>0&&(B-D)*(B-F)>0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}