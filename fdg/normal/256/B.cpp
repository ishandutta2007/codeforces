#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:256000000")

using namespace std;

long long sum(int n) {
    return 1LL*(n)*(n+1)/2;
}

long long get(int x,int y,int m) {
    long long ret=0;
    if (x<1||y<1||m<=0) return 0;
    int addx=max(m-x,0),addy=max(m-y,0);
    ret+=1LL*(addx)*(addx+1)/2+1LL*(addy)*(addy+1)/2;
    ret-=sum(max(m-x-y,0));
    return sum(m)-ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,x,y,c;
    cin >> n >> x >> y >> c;
    int l=0,r=2*n+1;
    while(r-l>1) {
        int m=(l+r)>>1;
        long long sum=get(x,y,m);
        sum+=get(x,n-y,m-1);
        sum+=get(n-x,y,m-1);
        sum+=get(n-x,n-y,m-2);
        if (sum>=c) r=m;
        else l=m;
    }
    cout << r-1 << endl;
//  cout << get(6,2,1000000000) << endl;
    return 0;
}