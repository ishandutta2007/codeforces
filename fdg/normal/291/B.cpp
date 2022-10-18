#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

using namespace std;

char str[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str); int l=strlen(str); str[l++]=' ';
    bool last=false,d=false;
    for(int i=0;i<l;++i) {
        if (!last&&(str[i]=='\"'||str[i]!=' ')) {
            last=true;
            printf("<");
            if (str[i]!='\"') printf("%c",str[i]);
            else d=true;
            continue;
        }
        if (last&&(str[i]=='\"'||d==false&&str[i]==' ')) {
            last=false; d=false;
            printf(">\n");
            continue;
        }
        if (last) printf("%c",str[i]);
    }
    return 0;
}