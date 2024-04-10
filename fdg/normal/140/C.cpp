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

int n,nums[100003];
int what[100000][3];

bool solve(int m) {
    memset(what,0,sizeof(what));
    int lev=0,pos=0;
    for(int i=n-1;i>=0&&lev<3;i--) {
        if (lev==0) {
            what[pos++][lev]=nums[i];
        } else {
            if (what[pos][lev-1]>nums[i])
                what[pos][lev]=nums[i],pos++;
        }
        if (pos==m) lev++,pos=0;
    }
    return lev==3;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&nums[i]);
    sort(nums,nums+n);
    int l=0,r=n/3+2;
    while(r-l>1) {
        int m=(l+r)>>1;
        if (solve(m)) l=m;
        else r=m;
    }
    solve(l);
    printf("%d\n",l);
    for(int i=0;i<l;i++)
        printf("%d %d %d\n",what[i][0],what[i][1],what[i][2]);
    return 0;
}