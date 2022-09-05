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
string m,n;
int cntm[257],cntn[257],ans;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n.size();i++)cntn[n[i]]++;
    for(int i=0;i<m.size();i++)cntm[m[i]]++;
    for(int i=0;i<=256;i++)
    {
        if(cntm[i]>0)
        {
            if(cntn[i]>0)ans+=min(cntn[i],cntm[i]);else{cout<<-1;return 0;}
        }
    }
    cout<<ans;
    return 0;
}