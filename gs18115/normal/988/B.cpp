#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
pair<string,int>s[123];
int n,i,j;
bool cmp(pair<string,int>x,pair<string,int>y)
{
    return x.second<y.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i].first;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(s[i].first.find(s[j].first,0)!=string::npos)
                s[i].second++;
            else
                s[j].second++;
        }
    }
    sort(s,s+n,cmp);
    for(i=0;i<n-1;i++)
    {
        if(s[i+1].first.find(s[i].first,0)==string::npos)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    for(i=0;i<n;i++)
        cout<<'\n'<<s[i].first;
    return 0;
}