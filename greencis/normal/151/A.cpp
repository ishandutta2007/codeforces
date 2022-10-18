#include <iostream>

using namespace std;

int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    cout<<min(min(k*l/nl/n,c*d/n),p/np/n);
    return 0;
}