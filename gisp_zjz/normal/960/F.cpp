#include<bits/stdc++.h>
#define maxn 200001

using namespace std;
typedef pair<int,int> pi;
struct node{
    int x,y;
};

map<pi,int>f;
int n,m,k,u,v,w,ans;

int qry(int x,int y)
{
    int rt=0;
    while (y){
        if (f.find({x,y})!=f.end()) rt=max(rt,f[{x,y}]);
        y-=y&(-y);
    }
    return rt;
}

void update(int x,int y,int z)
{
    while (y<maxn){
        if (f.find({x,y})!=f.end()) f[{x,y}]=max(f[{x,y}],z); else f[{x,y}]=z;
        y+=y&(-y);
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&w); w++;
        k=qry(u,w-1);
        update(v,w,k+1);
        ans=max(ans,k+1);
    }
    cout << ans << endl;
}