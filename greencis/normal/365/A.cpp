#include <iostream>

using namespace std;

int main()
{
    int n,k,res=0;
    cin>>n>>k;
    string s;
    while (n--) {
        cin>>s;
        int used[15] = {};
        for (int i = 0; i < s.length();++i)
            used[s[i]-'0'] = 1;
        int idx = 10;
        for (int i = 0; i < 10; ++i)
        if (!used[i]) {
            idx = i;
            break;
        }
        if (idx > k)++res;
    }
    cout<<res;
    return 0;
}