#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

bool compareStrings(const string &a, const string &b)
{
    string aString = a+b;
    string bString = b+a;
    return aString < bString;
}

int main()
{
    int N; cin >> N;
    vector<string> v(N);
    forn(i,N)
        cin >> v[i];
    sort(v.begin(), v.end(), compareStrings);
    forn(i,N)
        cout << v[i];
    cout << endl;
    return 0;
}