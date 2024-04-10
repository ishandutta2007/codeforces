#include <iostream>

using namespace std;

int main()
{
    int n,m,res=0;
    cin>>n>>m;
    for (int a = 0; a < 50; ++a) {
        for (int b = 0; b < 50; ++b) {
            if (a*a+b==n && b*b+a==m)
                ++res;
        }
    }
    cout << res;
    return 0;
}