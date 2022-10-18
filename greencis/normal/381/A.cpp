#include <iostream>

using namespace std;
int n,a[100006];
int main()
{
    cin>>n;
    for(int i =0;i<n;++i)cin>>a[i];
    int sc1=0;int sc2=0;
    int lb= 0,rb=n-1;
    int player = 0;
    while (lb<=rb) {
        if (a[lb] > a[rb]) {
            if (player) sc2 += a[lb], ++lb;
            else sc1 += a[lb], ++lb;
        } else {
            if (player) sc2 += a[rb];
            else sc1 += a[rb];
            --rb;
        }
        player = !player;
    }
    cout << sc1 << " " << sc2;
    return 0;
}