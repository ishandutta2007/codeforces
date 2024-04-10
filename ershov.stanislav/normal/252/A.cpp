#include <iostream>
#include <string>

using namespace std;
int n, x[111], a, b=0, m=-1;
int main()
{
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a;
        x[i+1]=x[i]^a;
    }
    for (int i=0; i<n; i++)
        for (int j=i+1; j<=n; j++) {
            if ((x[i]^x[j]) > m) m = x[i]^x[j];
        }
    cout << m;
    return 0;
}