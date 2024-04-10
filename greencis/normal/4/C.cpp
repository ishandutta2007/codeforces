#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string,int> m;
    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        m[s]++;
        if (m[s] == 1) cout << "OK\n";
        else cout << s << m[s]-1<<"\n";
    }
    return 0;
}