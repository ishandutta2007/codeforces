#include <iostream>

using namespace std;
int x,y,z,a,b,c;
int main()
{
    int n;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        x+=a,y+=b,z+=c;
    }
    cout<<(x==0 && y==0 &&z==0?"YES":"NO");

    return 0;
}