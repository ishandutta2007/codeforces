#include <iostream>

using namespace std;
int n,a[100500],m,x,y;
int main()
{
    cin>>n;
    for(int i =0;i<n;++i)cin>>a[i];
    cin>>m;
    while(m--){
        cin>>x>>y;
        if (n == 1) {
            a[0] = 0;
        } else {
            if (x == 1) {
                a[1] += a[0] - y;
                a[0] = 0;
            } else if (x == n) {
                a[n-1] = 0;
                a[n-2] += y - 1;
            } else {
                a[x] += a[x-1] - y;
                a[x-1] = 0;
                a[x-2] += y-1;

            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << a[i] <<endl;
    return 0;
}