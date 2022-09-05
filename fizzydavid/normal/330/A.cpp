#include<iostream>
#include<cstdlib>
using namespace std;
int n,m;
char str[100][100];
bool r[100],c[100];
int main()
{
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>str[i][j];
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(str[i][j]=='S')r[i]=1,c[j]=1;
    int ans=0;
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(!r[i]||!c[j])ans++;
    cout<<ans<<endl;    
    return 0;
}