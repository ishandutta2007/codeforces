#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n<3)cout<<-1;else{
        for(int i=n;i>0;--i)cout<<i<<" ";
    }
    return 0;
}