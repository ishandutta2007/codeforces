#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
#define end return 0
int main()
{
    string a[4];
    int ans=0,cnt=0;
    for(int i=0;i<4;i++)cin>>a[i];
    for(int i=0;i<4;i++)
    {
        int mx=0,mn=1000000;
        for(int j=0;j<4;j++)
        {
            if(i!=j){mx=max(int(a[j].size())-2,mx);mn=min(int(a[j].size())-2,mn);}
        }
        if((a[i].size()-2)*2<=mn||mx*2<=a[i].size()-2){ans=char('A'+i);cnt++;}
    }
    if(cnt>1||cnt==0)cout<<"C";else cout<<char(ans);
    end;
}