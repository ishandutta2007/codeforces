#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    cin >> k;
    if (k==0){
        cout<<0;
        return 0;
    }
    int a[12];
    for(int i = 0; i < 12;++i) {
        cin>>a[i];
    }
    sort(a,a+12);
    int r = 0, m = 0;
    for (int i = 11; i >= 0; --i) {
        m += a[i], ++r;
        if(m>=k) break;
    }
    cout << (m>=k?r:-1);
    return 0;
}