#include <iostream>

using namespace std;

int main()
{
    int n,t;
    cin >> n;
    int c=0,ci=0,nc=0,nci=0;
    for (int i = 0; i < n; ++i){
        cin>>t;
        if (t%2) {
            nc++;
            nci = i;
        }
        else {
            c++;
            ci = i;
        }
    }
    if (c == 1) {
        cout << ci+1;
    } else cout << nci+1;
    return 0;
}