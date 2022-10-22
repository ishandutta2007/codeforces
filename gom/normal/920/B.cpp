#include <bits/stdc++.h>
#define N 5005
using namespace std;
typedef pair<int,int> P;
int n,t;
int l[N],r[N],ans[N];
vector<int> m[N];
deque<int> dq;
int main()
{
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<=5000;i++)
            m[i].clear();
        dq.clear();
        scanf("%d",&n);
        fill(ans,ans+n+1,0);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&l[i],&r[i]);
            m[l[i]].push_back(i);
            //m[r[i]].push_back({i,0});
        }
        for(int i=1;i<=5000;i++){
            for(auto &it : m[i])
                dq.push_back(it);
            while(dq.size()!=0&&r[dq.front()]<i)
                dq.pop_front();
            if(dq.size()!=0){
                ans[dq.front()]=i;
                dq.pop_front();
            }
        }
        for(int i=1;i<=n;i++)
            printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}