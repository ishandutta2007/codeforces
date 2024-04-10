#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
vector<int> vecA[300005],vecB[300005];
int n,t,a[300005],b[300005],In[300005],Out[300005],ans,cnt;
set<pair<int,int> > st;
void dfsB(int x)
{
    In[x]=++cnt;
    for(int i=0;i<vecB[x].size();i++)
    {
        dfsB(vecB[x][i]);
    }
    Out[x]=++cnt;
}
void dfsA(int x)
{
    bool Del=false,Add=false;
    pair<int,int> tmp1=make_pair(0,0),tmp2=make_pair(0,10000000);
    if(st.size() && (st.lower_bound(make_pair(In[x],Out[x])))!=st.begin()) 
        tmp1=*(--st.lower_bound(make_pair(In[x],Out[x])));
    if(st.size() && (st.lower_bound(make_pair(In[x],Out[x])))!=st.end()) 
        tmp2=*st.lower_bound(make_pair(In[x],Out[x]));
    if(tmp1.second > Out[x]) 
    {
        Del=true;
        st.erase(tmp1);
    }
    if(tmp2.second > Out[x])
    {
        Add=true;
        st.insert(make_pair(In[x],Out[x]));
    }
    ans=max(ans,(int)st.size());
    for(int i=0;i<vecA[x].size();i++)
    {
        dfsA(vecA[x][i]);
    }
    if(Del) st.insert(tmp1);
    if(Add) st.erase(make_pair(In[x],Out[x]));
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        if(!st.empty()) printf("***\n");
        ans=cnt=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            vecA[i].clear();
            vecB[i].clear();
        }
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&a[i]);
            vecA[a[i]].push_back(i);
        }
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&b[i]);
            vecB[b[i]].push_back(i);
        }
        dfsB(1);
        dfsA(1);
        printf("%d\n",ans);
    }
}