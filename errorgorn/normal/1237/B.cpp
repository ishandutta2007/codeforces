#include <cstdio>
#include <queue>
using namespace std;
int n;
int arr[100005];
queue<int> q;
bool onstack[100005];
int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++) scanf("%d",&arr[x]);
    int t;
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        q.push(t);
        onstack[t]=true;
    }
    int ans=0;
    for (int x=0;x<n;x++){
        while (onstack[arr[x]]){
            if (q.front()!=arr[x]) ans++;
            onstack[q.front()]=false;
            q.pop();
        }
    }
    printf("%d\n",ans);
}