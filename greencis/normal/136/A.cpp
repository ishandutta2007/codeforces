#include <iostream>

using namespace std;

int main()
{
    int n,a[101],p[101];
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a[i];
        p[a[i]-1] = i+1;
    }
    for (int i=0;i<n;++i)
        cout << p[i]<<" ";

    return 0;
}