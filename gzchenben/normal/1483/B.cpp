#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,t,a[100005],L[100005],R[100005],del[100005];
vector<int> ans;
queue<int> Q;
int gcd(int x,int y)
{
    if(x>y) swap(x,y);
    if(x==0) return y;
    return gcd(y%x,x);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        while(!Q.empty()) Q.pop();
        ans.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            L[i]=i-1;
            R[i]=i+1;
            del[i]=0;
        }
        L[1]=n;
        R[n]=1;
        for(int i=1;i<=n;i++) Q.push(i);
        while(!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            if(del[x]) continue;
            if(gcd(a[x],a[R[x]])!=1) continue;
            del[R[x]]=true;
            ans.push_back(R[x]);
            int t1=x,t2=R[R[x]];
            R[t1]=t2;
            L[t2]=t1;
            Q.push(x);
        }
        printf("%d ",ans.size());
        for(int i=0;i<ans.size();i++)
        {
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}