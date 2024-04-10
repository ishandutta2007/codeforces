#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int res=0,a,b,c;
    while(n--){
        cin>>a>>b>>c;
        if(a+b+c>=2)++res;
    }
    cout<<res;
    return 0;
}