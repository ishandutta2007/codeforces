#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq;
int n;
int arr[300005];
int main(){
    scanf("%d",&n);
    for (int x=1;x<=n;x++){
        scanf("%d",&arr[x]);
    }
    long long ans=0;
    for (int x=n;x;x--){
        if (arr[x]==-1) break;
        pq.push(arr[x]);
        if (__builtin_popcount(x)==1){
            ans+=pq.top();
            pq.pop();
        }
    }

    printf("%lld\n",ans);
}