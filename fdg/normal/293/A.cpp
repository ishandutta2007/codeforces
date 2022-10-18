#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

char s1[2000002],s2[2000002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d\n",&n);
    gets(s1); gets(s2);
    int c1=0,c2=0,c3=0;
    for(int i=0;i<2*n;++i)
        if (s1[i]=='1'&&s2[i]=='1') ++c3;
        else if (s1[i]=='1') ++c1;
        else if (s2[i]=='1') ++c2;
    int t1=0,t2=0;
    t1=(c3+1)/2+c1; t2=(c3/2)+c2;
    if (t1>t2) puts("First");
    else if (t1<t2-1) puts("Second");
    else puts("Draw");
    return 0;
}