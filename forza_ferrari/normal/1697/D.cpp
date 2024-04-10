#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,pos[26],cnt;
pair<int,int> p[31];
string s;
int main()
{
    cin>>n;
    s.resize(n+1);
    cout<<"? 1 1"<<endl;
    cin>>s[1];
    pos[s[1]-'a']=1;
    for(int i=2;i<=n;++i)
    {
        cnt=0;
        for(int j=0;j<26;++j)
            if(pos[j])
                p[++cnt]={pos[j],j};
        sort(p+1,p+cnt+1,greater<pair<int,int> >());
        int l=1,r=cnt,mid,ans=-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            cout<<"? 2 "<<p[mid].first<<" "<<i<<endl;
            int x;
            cin>>x;
            if(x==mid)
            {
                r=mid-1;
                ans=mid;
            }
            else
                l=mid+1;
        }
        if(ans==-1)
        {
            cout<<"? 1 "<<i<<endl;
            cin>>s[i];
        }
        else
            s[i]=p[ans].second+'a';
        pos[s[i]-'a']=i;
    }
    s.erase(s.begin());
    cout<<"! "<<s<<endl;
    return 0;
}