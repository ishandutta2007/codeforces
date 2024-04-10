#include <iostream>

using namespace std;

int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    while (k--) {
        string s_b = s;
        for (int i = n-2; i >= 0; --i) {
            if (s_b[i] == 'B' && s_b[i+1] != 'B')
                swap(s[i],s[i+1]);
        }
    }
    cout << s;
    return 0;
}