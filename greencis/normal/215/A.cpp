#include <iostream>
#include <map>
using namespace std;

int n,m,a[99],b[99];
map<int,int> mp;

int main()
{
    int mx = 0;
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    cin>>m;
    for(int i=0;i<m;++i)cin>>b[i];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[j] % a[i] == 0) {
                ++mp[b[j] / a[i]];
                if (b[j] / a[i] > mx) {
                    mx = b[j] / a[i];
                }
            }
        }
    }
    
    cout << mp[mx];

    return 0;
}