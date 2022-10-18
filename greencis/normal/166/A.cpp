#include <iostream>
#include <algorithm>
using namespace std;

int n,k,res=0,e[10005],a,b;

int main()
{
    cin >> n >> k;
    for (int i=0;i<n;++i)
        cin>>a >>b,e[i] = a*10000-b;
    sort(e,e+n);
    for (int i=0;i<n;++i){
        if(e[i] == e[n-k]) ++res;
    }
    cout << res;
    return 0;
}