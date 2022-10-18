#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

string t = "eoaiuy";
string s = "aaaa";

int n,l,r,x;

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> a,b;
    cin>>n>>l>>r;
    for(int i=0;i<n;++i){
        cin>>x;
        a.push_back(x);
    }
    for(int i=0;i<n;++i){
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin() + l-1, a.begin()+r);
    sort(b.begin() + l-1, b.begin()+r);
    cout <<(a==b?"TRUTH":"LIE");

    /*ofstream fout("output.txt");

    for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                    for (int z = 0; z < 2; ++z) {
                        if (t[z] - 97 == i || t[z] - 97 == j) continue;
                        s[1] = s[2] = t[z];
                    s[0] = 'a' + i;
                    s[3] = 'a' + j;
                    string s2 = s;
                    s2[1] -= 32;
                    s2[2] -= 32;
                    fout << "$a=$p(\"" << s << "\",\"" << s2 << "\",$a);" << endl;
                    }
                }
            }*/


    return 0;
}