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

int pos[100002],neg[100002],num[100002];
char w[100002];
int ans[100002];
bool can[100002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;++i) {
        scanf("%c%d\n",&w[i],&num[i]); --num[i];
        if (w[i]=='+') pos[num[i]]++;
        else neg[num[i]]++;
    }
    int sum=0,cnt=0;
    for(int i=0;i<n;++i)
        sum+=neg[i];
    for(int i=0;i<n;++i) {
        if (pos[i]+sum-neg[i]==m) can[i]=true,++cnt;
    }
    for(int i=0;i<n;++i) {
        if (w[i]=='+') {
            if (can[num[i]]) {
                if (cnt==1) ans[i]=1;
            } else {
                ans[i]=-1;
            }
        } else {
            if (can[num[i]]) {
                if (cnt==1) ans[i]=-1;
            } else {
                ans[i]=1;
            }
        }
    }
    for(int i=0;i<n;++i)
        if (ans[i]==1) puts("Truth");
        else if (ans[i]==0) puts("Not defined");
        else puts("Lie");
    return 0;
}