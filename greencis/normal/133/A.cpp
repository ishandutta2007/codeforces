#include <iostream>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    for(int i=0;s[i];++i) {
        if (s[i] == 'H' || s[i]=='Q'||s[i]=='9') {
            cout<<"YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}