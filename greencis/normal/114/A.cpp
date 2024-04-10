#include <iostream>

using namespace std;

int main()
{
    long long x,y,deg=0;
    cin>>x>>y;
    for (long long i = x; i <= y; i*=x) {
        if (i == y) {
            cout<<"YES\n";
            cout<<deg;
            return 0;
        }
        ++deg;

    }
    cout << "NO";
    return 0;
}