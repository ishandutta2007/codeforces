#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
using namespace std;
struct data
{
    string s;
    int id;
    bool operator<(data tmp)const{
        return s<tmp.s;
    }
};
data s[200111];
int p[100111],n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i*2-1].s>>s[i*2].s;
        s[i*2-1].id=s[i*2].id=i;
    }
    sort(s+1,s+n*2+1);
    for(int i=1;i<=n;i++)cin>>p[i];
    int j=1;
    for(int i=1;i<=n*2;i++)
    {
        if(s[i].id==p[j])j++;
        if(j==n+1)break;
    }
    if(j==n+1)cout<<"YES";else cout<<"NO";
    return 0;
}