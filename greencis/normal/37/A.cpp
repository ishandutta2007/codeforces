#include <iostream>
#include <map>
using namespace std;

map<int,int> mp;

int main()
{
    int n,res1=0,res2=0;
    cin>>n;
    while(n--){
        int t;
        cin >> t;
        mp[t]++;
        if (mp[t] == 1) ++res2;
        res1=max(res1,mp[t]);
    }
    cout << res1 << " " << res2;
    return 0;
}