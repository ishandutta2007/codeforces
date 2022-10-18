#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int t,n,minn,maxn;
multiset<int> s1,s2,s3;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        minn=maxn=-1;
        s1.clear();
        s2.clear();
        s3.clear();
        for(int i=1;i<=n;++i)
        {
            int l,r,w;
            cin>>l>>r>>w;
            if(minn==-1)
            {
                minn=l;
                maxn=r;
                s3.emplace(w);
            }
            else if(l==minn&&r==maxn)
                s3.emplace(w);
            else if(l<minn&&r>maxn)
            {
                minn=l;
                maxn=r;
                s1.clear();
                s2.clear();
                s3.clear();
                s3.emplace(w);
            }
            else if(l==minn&&r>maxn)
            {
                maxn=r;
                s1.insert(s3.begin(),s3.end());
                s2.clear();
                s3.clear();
                s3.emplace(w);
            }
            else if(l<minn&&r==maxn)
            {
                minn=l;
                s1.clear();
                s2.insert(s3.begin(),s3.end());
                s3.clear();
                s3.emplace(w);
            }
            else if(l==minn)
                s1.emplace(w);
            else if(r==maxn)
                s2.emplace(w);
            else if(l<minn)
            {
                minn=l;
                s1.clear();
                s1.emplace(w);
                s2.insert(s3.begin(),s3.end());
                s3.clear();
            }
            else if(r>maxn)
            {
                maxn=r;
                s1.insert(s3.begin(),s3.end());
                s2.clear();
                s2.emplace(w);
                s3.clear();
            }
            int ans=2e9;
            if(!s3.empty())
                ans=*s3.begin();
            if(!s1.empty()&&!s2.empty())
                ans=min(ans,*s1.begin()+*s2.begin());
            cout<<ans<<'\n';
        }
    }
    return 0;
}