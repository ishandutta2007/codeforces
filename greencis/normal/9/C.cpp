#include <iostream>

using namespace std;

int r=0,n;

void lookup(int x) {
    if(x>n) return;
    ++r;
    lookup(x*10);
    lookup(x*10+1);
}

int main()
{
    cin>>n;
    lookup(1);
    cout<<r;
    return 0;
}