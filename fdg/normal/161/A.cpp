#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <memory.h>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

pair<int,int> arr1[100002],arr2[100002];
vector < pair <int,int> > ans;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<n;++i) {
        scanf("%d",&arr1[i].first);
        arr1[i].second=i;
    }
    for(int i=0;i<m;++i) {
        scanf("%d",&arr2[i].first);
        arr2[i].second=i;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
    int cur=0;
    for(int i=0;i<n;++i) {
        while(cur<m&&arr2[cur].first<arr1[i].first-x) ++cur;
        if (cur<m&&arr1[i].first-x<=arr2[cur].first&&arr2[cur].first<=arr1[i].first+y) {
            ans.push_back(make_pair(arr1[i].second+1,arr2[cur].second+1));
            ++cur;
        }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();++i)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}