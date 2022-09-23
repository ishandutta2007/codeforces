#include <iostream>
#include <map>
using namespace std;
int main()
{
    int a,b,c[301],i;
    map<int,int>m;
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
        cin>>c[i];
    }
    for( i=1; i<=b; i++ ){
        if(m[c[i]%a]>0){
            cout<<i;
            return 0;
        }
        m[c[i]%a]++;
    }
    cout<<-1;
    return 0;
}