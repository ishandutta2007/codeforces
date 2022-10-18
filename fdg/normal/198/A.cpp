#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <map>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int k,b,n,t;
    cin >> k >> b >> n >> t;
    long long z=1,ans=0;
    while(z<=t) z=k*z+b,++ans;
    cout << max(n-ans+1,0LL) << endl;
    return 0;
}