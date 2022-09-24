#include<iostream>
#include<set>
using namespace std;
set<int>S;
int N,i,a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>a;
        if(a)
            S.insert(a);
    }
    cout<<S.size();
    return 0;
}