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

map < pair<long long,long long>,bool > f;

bool go(long long a,long long b) {
    if (a>b) swap(a,b);
    if (a==0) return false;
    if (b%a==0) return true;
    if (f.count(make_pair(a,b))) return f[make_pair(a,b)];
    bool lose=!go(b%a,a);
    if (!lose) {
        b-=b%a;
        if (a>1000000000||(a&1)) lose=(b/a)%2==0;
        else {
            b%=a*(a+1); b/=a;
            if (b>=a||b%2==0) lose=true;
            else lose=false;
        }
    }
    return f[make_pair(a,b)]=lose;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int T; long long a,b;
    cin >> T;
    for(int i=0;i<T;++i) {
        cin >> a >> b;
        if (go(a,b)) puts("First");
        else puts("Second");
    }
    return 0;
}