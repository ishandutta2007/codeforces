#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int n,m,lst,ans;
string s,t;
vector<int> v[26];
stack<int> t1,t2;
int main()
{
    scanf("%d%d",&n,&m);
    cin>>s>>t;
    for(register int i=0;i<n;++i)
        v[s[i]-'a'].push_back(i);
    t1.push(v[t[0]-'a'][0]);
    lst=n;
    for(register int i=m-1;i>0;--i)
    {
        lst=v[t[i]-'a'][lower_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),lst)-v[t[i]-'a'].begin()-1];
        t2.push(lst);
    }
    ans=t2.top()-t1.top();
    lst=t1.top();
    for(register int i=1;i<m-1;++i)
    {
        lst=v[t[i]-'a'][upper_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),lst)-v[t[i]-'a'].begin()];
        t1.push(lst);
        t2.pop();
        ans=max(ans,t2.top()-t1.top());
    }
    printf("%d\n",ans);
    return 0;
}