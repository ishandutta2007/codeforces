#include<iostream>
#define fr(a,b,c) for (a=b;a<=c;a++)
using namespace std;
const char a[7]={'R','O','Y','G','B','I','V'};

int main()
{
    int n,i;
    cin >> n;
    n--;
    fr(i,0,n-3) cout << a[i%4];
    fr(i,4,6) cout << a[i];
    cout << endl;
    return 0;
}