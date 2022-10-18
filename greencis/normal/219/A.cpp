#include <iostream>

using namespace std;

int freq[256];

int main()
{
    int k;
    string s;
    cin>>k>>s;
    for (int i=0;i<s.length();++i)
        freq[s[i]]++;

    bool ok = true;
    for (int i = 0; i < 256; ++i) {
        if (freq[i] % k){
            ok = false;
            break;
        }
    }

    if (!ok) {
        cout << "-1";
        return 0;
    }

    for (int q = 0; q < s.length(); ) {
        for (int i = 0; i < 256; ++i) {
            for (int j = 0; j < freq[i] / k; ++j)
                cout << (char)i, ++q;
        }
    }

    return 0;
}