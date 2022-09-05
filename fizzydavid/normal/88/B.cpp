#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int dist(int x1,int y1,int x2,int y2)
{
    return abs((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
char a[52][52];
bool ok[150],word[150];
string t;
int tl,n,m,x;
int main()
{
    int i,j,k,l,sum=0;
    cin>>n>>m>>x;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++){cin>>a[i][j];if(a[i][j]!='S')word[(int)a[i][j]]=word[(int)a[i][j]-32]=1;}
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
        if(a[i][j]=='S'){
            word[0]=1;
            for(k=1;k<=n;k++)for(l=1;l<=m;l++)
                if(dist(i,j,k,l)<=x*x&&dist(i,j,k,l)!=0)ok[(int)a[k][l]]=1;}
    cin>>tl;
    cin>>t;
    for(i=0;i<tl;i++)
    {
        if(word[(int)t[i]]==0){cout<<"-1";return 0;}
        if(t[i]>='A'&&t[i]<='Z')
        {
            if(word[0]==0){cout<<"-1";return 0;}
            sum+=!ok[t[i]+32];
        }
    }
    cout<<sum;
    return 0;
}