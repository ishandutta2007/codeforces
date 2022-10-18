#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory.h>

using namespace std;

char str[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int n=strlen(str),l=0,q=0;
    bool was[256]={0};
    for(int i=0;i<n;++i) {
        if (str[i]=='?') ++q;
        else if (str[i]>='A'&&str[i]<='J') {
            l+=!was[str[i]];
            was[str[i]]=true;
        }
    }
    long long p1=1,p2=0; int q1=0,q2=0;
    for(int i=0;i<l;++i) p1*=(10-i);
    q1=q;
    if (str[0]=='?') {
        p2=1; --q;
        for(int i=0;i<l;++i) p2*=(10-i);
        q2=q; q1--; p1*=10;
        p1-=p2;
    }
    else if (str[0]>='A'&&str[0]<='J') {
        p2=1;
        for(int i=1;i<l;++i) p2*=(10-i);
        q2=q;
        p1-=p2;
    }
    printf("%I64d",p1);
    for(int i=0;i<q1;++i)
        printf("0");
    printf("\n");
    return 0;
}