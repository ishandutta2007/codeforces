#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string str;
    int ans = 0;
    cin >> n;
    cin >> str;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '1') ans ++;
        else break;
    }
    if(ans < str.length()) ans++;
    cout << ans << endl;
    return 0;
}