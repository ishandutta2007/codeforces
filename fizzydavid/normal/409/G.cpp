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
#include<ctime>
#include<utility>
#include<vector>
using namespace std;
float n,x,ans;
int main()
{
    cin>>n>>x>>x;ans=x;
    for(int i=2;i<=n;i++){cin>>x>>x;ans+=x;}
    cout<<5+ans/n;
    return 0;
}