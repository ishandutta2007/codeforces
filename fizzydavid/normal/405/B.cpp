#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
int a[3111],b[3111],n;
string s;
int main()
{
    cin>>n>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')for(int k=0;i+k<n&&s[i+k]=='.'||k==0;k++)a[i+k]=k+1;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='L')for(int k=0;i-k>=0&&s[i-k]=='.'||k==0;k++)b[i-k]=k+1;
    }
    int sum=0;
    for(int i=0;i<n;i++)if(a[i]==0&&b[i]==0||a[i]==b[i])sum++;
    cout<<sum;
    return 0;
}