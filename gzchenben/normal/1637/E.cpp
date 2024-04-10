#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,m,t,a[300005],cntID,RevID[10005],Nxt[10005];
map<int,int> Cnt,vecID;
map<pair<int,int>,bool> Bad; 
vector<int> Vec[10005];

struct Node
{
    int cnt,val;
};
Node Now;
bool operator <(Node x,Node y)
{
    long long tx=(long long)(Now.cnt+x.cnt)*(Now.val+x.val);
    long long ty=(long long)(Now.cnt+y.cnt)*(Now.val+y.val);
    return tx<ty;
}
priority_queue<Node> Q;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        long long ans=0;
        Cnt.clear();
        vecID.clear();
        Bad.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            Cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            int tmpx,tmpy;
            scanf("%d%d",&tmpx,&tmpy);
            Bad[make_pair(tmpx,tmpy)]=true;
            Bad[make_pair(tmpy,tmpx)]=true;
        }
        for(auto &p : Cnt)
        {
            if(vecID[p.second]==0) 
            {
                vecID[p.second]=++cntID;
                RevID[cntID]=p.second;
            }
            Vec[vecID[p.second]].push_back(p.first); 
        }
        for(int i=1;i<=cntID;i++) sort(Vec[i].begin(),Vec[i].end(),cmp);
        for(auto &p : Cnt)
        {
            Now=(Node){p.second,p.first};
            for(int i=1;i<=cntID;i++)
            {
                Q.push((Node){RevID[i],Vec[i][0]});
                Nxt[i]=1;
            }
            while(!Q.empty())
            {
                Node tmp=Q.top();
                Q.pop();
                if(Bad[make_pair(Now.val,tmp.val)] || tmp.val==Now.val)
                {
                    int pos=vecID[tmp.cnt];
                    if(Nxt[pos]==Vec[pos].size()) continue;
                    Q.push((Node){tmp.cnt,Vec[pos][Nxt[pos]]});
                    Nxt[pos]++;
                    continue;
                }
                long long NowAns=(long long)(Now.cnt+tmp.cnt)*(Now.val+tmp.val);
                ans=max(ans,NowAns);
                break;
            }
            while(!Q.empty()) Q.pop();
        }
        printf("%lld\n",ans);
        for(int i=1;i<=cntID;i++)
        {
            Vec[i].clear();
        }
        cntID=0;
    }
}