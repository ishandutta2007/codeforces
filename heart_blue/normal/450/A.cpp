#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int k = -1;
    for(int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int cnt = a/m;
        if(a%m) cnt++;
        if(ans <= cnt) ans = cnt, k = i;
    }
    cout << k << endl;
    return 0;
        
}