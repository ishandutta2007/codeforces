#include <iostream>
#include <algorithm>
using namespace std;

struct entry {
    int a,b;
} e[100005];

int s,n;

int comp(entry a, entry b) {
    return a.a < b.a;
}

int main()
{
    cin>>s>>n;
    for (int i = 0; i < n; ++i)
        cin >> e[i].a >> e[i].b;

    sort(e,e+n,comp);
    for (int i = 0; i < n; ++i) {
        if (s <= e[i].a) {
            cout << "NO";
            return 0;
        }
        s += e[i].b;
    }
    cout << "YES";

    return 0;
}