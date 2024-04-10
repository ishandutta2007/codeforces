#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cin >> n>>m;
    if(n>=2*m)cout << m;
    else if(m>=2*n) cout << n;
    else cout<< (m+n)/3;
    //cout << "Hello world!" << endl;
    return 0;
}