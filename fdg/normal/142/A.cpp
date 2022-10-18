#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    int f=sqrt(n+1.0);
    long long mn=-1,mx=-1,stoled;
    for(int i=1;i<=f;++i) {
        if (n%i==0) {
            int k=n/i,f1=sqrt(k+1.0);
            for(int j=1;j<=f1;j++)
                if (k%j==0) {
                    stoled=1LL*(i+1)*(j+2)*(k/j+2)-n;
                    if (mn==-1||stoled<mn) mn=stoled;
                    if (mx<stoled) mx=stoled;
                }
            k=i,f1=sqrt(k+1.0);int r=n/i;
            for(int j=1;j<=f1;j++)
                if (k%j==0) {
                    stoled=1LL*(r+1)*(j+2)*(k/j+2)-n;
                    if (mn==-1||stoled<mn) mn=stoled;
                    if (mx<stoled) mx=stoled;
                }
        }
    }
    cout << mn << " " << mx << endl;
    return 0;
}