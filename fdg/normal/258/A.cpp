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

char str[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int n=strlen(str),pos=n-1;
    for(int i=0;i<n;++i)
        if (str[i]=='0') {
            pos=i;
            break;
        }
    for(int i=0;i<n;++i)
        if (i!=pos) printf("%c",str[i]);
    printf("\n");
    return 0;
}