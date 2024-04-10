#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    char s[2002]={0},t[2002]={0};
    gets(s); gets(t);
    int l1=strlen(s),l2=strlen(t),ans=l2;
    for(int i=-l2;i<l1;++i) {
        int cur=0;
        for(int j=0;j<l2;++j)
            if (i+j>=0&&i+j<l1&&s[i+j]==t[j]);
            else ++cur;
        ans=min(ans,cur);
    }
    cout << ans << endl;
    return 0;
}