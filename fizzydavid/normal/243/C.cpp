//By FizzyDavid
#include<bits/stdc++.h>
using namespace std;
inline char mygetchar()
{
    char c=getchar();
    while(c==' '||c=='\n')
        c=getchar();
    return c;
}
int n;
long long lenx[2011],leny[2011];
int sn,sm;
bool f[2011][2011],vis[2011][2011];
vector<pair<int,int> >pos;
vector<int>cx,cy;
void dfs(int x,int y)
{
    if(x<1||x>sn||y<1||y>sm||f[x][y]||vis[x][y])
        return;
    vis[x][y]=1;
    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}
int dir(int x)
{
    return x<0?-1:1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    char op;
    int t,x=0,y=0;
    pos.push_back(make_pair(0,0));
    cx.push_back(0);
    cy.push_back(0);
    for(int i=1;i<=n;i++)
    {
        cin>>op>>t;
        switch(op){
        case 'U':y+=t;break;
        case 'D':y-=t;break;
        case 'L':x-=t;break;
        case 'R':x+=t;break;
        }
        pos.push_back(make_pair(x,y));
        cx.push_back(x);
        cy.push_back(y);
    }
    sort(cx.begin(),cx.end());
    sort(cy.begin(),cy.end());
    cx.erase(unique(cx.begin(),cx.end()),cx.end());
    cy.erase(unique(cy.begin(),cy.end()),cy.end());
    for(int i=0;i<cx.size();i++)
    {
        lenx[++sn]=1;
        if(i+1<cx.size()&&cx[i]+1<cx[i+1])
            lenx[++sn]=cx[i+1]-cx[i]-1;
    }
    for(int i=0;i<cy.size();i++)
    {
        leny[++sm]=1;
        if(i+1<cy.size()&&cy[i]+1<cy[i+1])
            leny[++sm]=cy[i+1]-cy[i]-1;
    }
    int ts;
    ts=int(cx.size())-1;
    for(int i=0;i<ts;i++)
        if(cx[i]+1<cx[i+1])
            cx.push_back(cx[i]+1);
    ts=int(cy.size())-1;
    for(int i=0;i<ts;i++)
        if(cy[i]+1<cy[i+1])
            cy.push_back(cy[i]+1);
    sort(cx.begin(),cx.end());
    sort(cy.begin(),cy.end());
    for(int i=0;i<=n;i++)
    {
        pos[i].first=lower_bound(cx.begin(),cx.end(),pos[i].first)-cx.begin()+1;
        pos[i].second=lower_bound(cy.begin(),cy.end(),pos[i].second)-cy.begin()+1;
    }
    for(int i=1;i<=n;i++)
    {
        for(x=pos[i-1].first;;x+=dir(pos[i].first-pos[i-1].first))
        {
            for(y=pos[i-1].second;;y+=dir(pos[i].second-pos[i-1].second))
            {
                f[x][y]=1;
                if(y==pos[i].second)
                    break;
            }
            if(x==pos[i].first)
                break;
        }
    }
    for(int i=1;i<=sm;i++)
    {
        if(!vis[1][i])
            dfs(1,i);
        if(!vis[sn][i])
            dfs(sn,i);
    }
    for(int i=1;i<=sn;i++)
    {
        if(!vis[i][1])
            dfs(i,1);
        if(!vis[i][sm])
            dfs(i,sm);
    }
    long long ans=0;
    for(int i=1;i<=sn;i++)
        for(int j=1;j<=sm;j++)
            if(!vis[i][j])
                ans+=lenx[i]*leny[j];
    cout<<ans<<endl;
            
    return 0;
}