#include <iostream>
#include <map>
using namespace std;
int n,a,res=0;
map<int,int> mp;
int main()
{
    cin>>n;
    for (int i =0;i<n;++i){
        cin>>a;
        ++mp[a];
        if (a!=0) {
            if (mp[a] == 2) ++res;
            if (mp[a] > 2) {cout << -1;return 0;}
        }
    }
    cout << res;

    return 0;
}