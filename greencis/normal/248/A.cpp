#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int n,l,r,x,y;
int main()
{
    cin >> n;
    for (int i=0;i<n;++i){
    cin>>x>>y;l+=x;r+=y;
    }cout<<min(l,n-l)+min(r,n-r);
    return 0;
}