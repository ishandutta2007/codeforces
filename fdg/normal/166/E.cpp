#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,mod=1000000007,d[4]={0};
    cin >> n;
    d[0]=1;
    for(int i=0;i<n;++i) {
        int sum=(0LL+d[0]+d[1]+d[2]+d[3])%mod;
        for(int j=0;j<4;++j) {
            d[j]=(sum-d[j]+mod)%mod;
        }
    }
    cout << d[0] << endl;
    return 0;
}