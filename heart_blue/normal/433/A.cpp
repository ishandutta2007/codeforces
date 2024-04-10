#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x,y;
    int z;
    x = y = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> z;
        if(z == 100) x++;
        else y++;
    }
    int sum = x+y*2;
    string ans = "NO";
    for(int i = 0; i <= y; i++)
    {
        if(sum&1) break;
        if(i*2 > sum/2) break;
        if(i*2+x >= sum/2)
        {
            ans = "YES";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}