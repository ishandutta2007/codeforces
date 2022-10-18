#include <iostream>

using namespace std;

int d[105],s;

int main()
{
    int n;
    cin>>n;
    for (int i =1;i<=n;++i){
        int q;
        cin>>q;
        s+=q;
        if (q!=0) q=-1;
        else q = 1;
        d[i] = max(q + d[i-1], q);
        d[0] = max(d[0], d[i]);
    }
    cout << d[0] + s-(s==n);
    return 0;
}