#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    int pre = 0;
    int ans = 0;
    while(n--)
    {
        cin >> x;
        if(x == 0) 
        {
            pre = x;
            continue;
        }
        if(pre == 1) ans ++;
        else ans += 2;
        pre = x;
    }
    if(ans) ans--;
    cout << ans << endl;
    return 0;
}