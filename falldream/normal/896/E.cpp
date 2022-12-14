#include<iostream>
#include<cstdio>
#include<vector>
#define MN 100000
#define MB 320
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
vector<int> v[MN+5];
int n,m,a[MN+5],s[MN/MB+5][MN+5],block[MN+5],Add[MN+5],val[MN+5],mx[MN+5];
int Merge(int x,int y)
{
    if(!x||!y) return x|y;
    if(v[x].size()<v[y].size())	swap(x,y);
    for(;v[y].size();v[y].pop_back()) v[x].push_back(v[y].back());
    return x;
}
void Build(int x)
{
    int l=(x-1)*MB+1,r=min(n,x*MB);mx[x]=0;
    for(int i=l;i<=r;++i)
    {
        s[x][val[i]]=0;
        while(v[i].size()) v[i].pop_back();
    }
    for(int i=l;i<=r;++i)
    {
        mx[x]=max(mx[x],a[i]);
        if(!s[x][a[i]]) s[x][a[i]]=i,val[i]=a[i];
        v[s[x][a[i]]].push_back(i);
    }
}

void Update(int x)
{
    int l=(x-1)*MB+1,r=min(n,x*MB);
    for(int i=l;i<=r;++i) for(int j=0;j<v[i].size();++j) a[v[i][j]]=val[i];
}

int main()
{
    n=read();m=read();
    for(int i=1;i<=n;++i) a[i]=read(),block[i]=(i-1)/MB+1;
    for(int i=1;i<=block[n];++i) Build(i);
    for(int q=1;q<=m;++q)
    {
        int op=read(),l=read(),r=read(),x=read();
        if(op==1)
        {
            Update(block[l]);
            for(int i=l;i<=r&&block[i]==block[l];++i) if(a[i]+Add[block[i]]>x) a[i]-=x;
            Build(block[l]);
            if(block[l]!=block[r])
            {
                Update(block[r]);
                for(int i=r;block[i]==block[r];--i) if(a[i]+Add[block[i]]>x) a[i]-=x;
                Build(block[r]);
            }
            for(int i=block[l]+1;i<block[r];++i)
            {
                if(mx[i]+Add[i]<=x) continue;
                if(mx[i]+Add[i]<=2*x)
                {
                    for(int j=x-Add[i]+1;j<=mx[i];++j)
                        s[i][j-x]=Merge(s[i][j-x],s[i][j]),val[s[i][j-x]]=j-x,s[i][j]=0;
                    while(!s[i][mx[i]]) --mx[i];
                }
                else
                {
                    for(int j=1-Add[i];j<=x-Add[i];++j)
                        s[i][j+x]=Merge(s[i][j+x],s[i][j]),val[s[i][j+x]]=j+x,s[i][j]=0;
                    Add[i]-=x;
                }
            }
        }
        else
        {
            int res=0;Update(block[l]);
            for(int i=l;i<=r&&block[i]==block[l];++i) if(a[i]+Add[block[i]]==x) ++res;
            if(block[l]!=block[r])
            {
                Update(block[r]);
                for(int i=r;block[i]==block[r];--i) if(a[i]+Add[block[i]]==x) ++res;	
            }
            for(int i=block[l]+1;i<block[r];++i) res+=(x-Add[i]<=MN)?v[s[i][x-Add[i]]].size():0;
            printf("%d\n",res);
        }
    }
    return 0;
}