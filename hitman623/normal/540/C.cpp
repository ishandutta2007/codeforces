#include <bits/stdc++.h>
using namespace std;
map < long , vector <long > > ad;
long visi[1000000]={0};
void dfs(long node)
{
    visi[node]=1;
    long i=0;
    for(i=0;i<ad[node].size();++i)
    {
        if(!visi[ad[node][i]])
            dfs(ad[node][i]);
    }
}
int main()
{
    long n,m,x1,y1,x2,y2,i,j,g=0,f=0;
    char a[500][500];
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>a[i];
    cin>>x1>>y1>>x2>>y2;
    if(a[x2-1][y2-1]=='X') f=1;
    a[x2-1][y2-1]='.';
    if(a[x1-1][y1-1]=='X') g=1;
    a[x1-1][y1-1]='.';
    for(i=0;i<n;++i)
    for(j=0;j<m;++j)
    {
        if(a[i][j]=='.')
        {
            if(i>0)
            {
                if(a[i-1][j]=='.') ad[m*(i)+j+1].push_back(m*(i-1)+j+1);
            }
            if(i<n-1)
            {
                if(a[i+1][j]=='.') ad[m*(i)+j+1].push_back(m*(i+1)+j+1);
            }
            if(j>0)
            {
                if(a[i][j-1]=='.') ad[m*(i)+j+1].push_back(m*(i)+j);
            }
            if(j<m-1)
            {
                if(a[i][j+1]=='.') ad[m*(i)+j+1].push_back(m*(i)+j+2);
            }
        }
    }
       dfs(m*(x1-1)+y1);
       if(!visi[m*(x2-1)+y2]) {cout<<"NO";}
       else
       {
           if(f==0) { if(ad[m*(x2-1)+y2].size()>1) cout<<"YES"; else cout<<"NO";}
           else if(ad[m*(x2-1)+y2].size()>0) cout<<"YES";
           else cout<<"NO";
       }
        return 0;
}