#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
int n,l,r;
iii arr[100005];
set<int> s;
int fin[100005];
int main(){
    scanf("%d%d%d",&n,&l,&r);
    for (int x=0;x<n;x++) scanf("%d",&arr[x].first.first);
    for (int x=0;x<n;x++) scanf("%d",&arr[x].first.second);
    for (int x=0;x<n;x++) arr[x].second=x;
    sort(&arr[0],&arr[n],[](iii i,iii j){
        return i.first.second<j.first.second;
    });
    int lb=-2123456789;
    for (int x=0;x<n;x++){
        int curr=l;
        int delta=curr-arr[x].first.first;
        if (delta<lb){
            curr+=lb-delta;
        }
        if(curr>r){
            printf("-1\n");
            return 0;
        }
        //printf("candidate: %d %d\n",curr,curr-arr[x].first.first);
            if (curr>r){
                printf("-1\n");
                return 0;
            }
        //printf("%d %d\n",arr[x].second,curr);
        fin[arr[x].second]=curr;
        
        lb=curr-arr[x].first.first+1;
    }
    
    for (int x=0;x<n;x++){
        printf("%d ",fin[x]);
    }
}