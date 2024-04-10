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
int n,su,sd;
bool f;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;cin>>x>>y;
        if((x^y)&1)f=1;
        su=(x&1)^su;sd=(y&1)^sd;
    }
    if(su^sd)cout<<-1;
    else if(su==0)cout<<0;
    else if(f)cout<<1;
    else cout<<-1;
    return 0;
}