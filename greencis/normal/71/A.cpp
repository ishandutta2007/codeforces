#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while (n--) {
        char p[101]={};
        cin >> p;
        int len = strlen(p);
        if (len > 10) {
            cout << p[0] << len-2 << p[len-1];
        }
        else cout << p;
        cout << endl;
    }
    return 0;
}