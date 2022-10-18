#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,z[10000005],cnt;
string s,t,str,ans;
pair<int,int> a[5000005];
int main()
{
    cin>>s>>m;
    n=s.length();
    t=s;
    reverse(t.begin(),t.end());
    if(m==1)
    {
        cout<<(s<t? s:t)<<'\n';
        return 0;
    }
    str=" "+t;
    for(int i=1,j,k;i<=n;)
    {
        j=i+1;
        k=i;
        while(j<=n&&str[k]<=str[j])
        {
            if(str[k]<str[j])
                k=i;
            else
                ++k;
            ++j;
        }
        a[++cnt]={i,j-k};
        while(i<=k)
            i+=j-k;
    }
    a[cnt+1].first=n+1;
    while(cnt&&m>=3)
    {
        for(int i=a[cnt].first;i<a[cnt+1].first;++i)
            ans.push_back(str[i]);
        if(a[cnt].second!=1||a[cnt-1].second!=1)
            --m;
        --cnt;
    }
    if(!cnt)
    {
        cout<<ans<<'\n';
        return 0;
    }
    string tmp,res;
    n=a[cnt+1].first-1;
    for(int i=0;i<n;++i)
        tmp.push_back(t[i]);
    s=t=tmp;
    reverse(s.begin(),s.end());
    res=s;
    //cerr<<res<<'\n';
    int qwq=1;
    str=" "+t+t;
    int pos=0;
    for(int i=1,j,k;i<=n;)
    {
        j=i+1;
        pos=k=i;
        while(j<=n+n&&str[k]<=str[j])
        {
            if(str[k]<str[j])
                k=i;
            else
                ++k;
            ++j;
        }
        while(i<=k)
            i+=j-k;
    }
    if((tmp=str.substr(pos,n))<res)
    {
        res=tmp;
        qwq=2;
    }
    //cerr<<tmp<<'\n';
    str=" "+t+s;
    z[1]=n+n;
    for(int i=2,l=0,r=0;i<=n+n;++i)
    {
        if(i>r)
        {
            l=r=i;
            while(r<=n+n&&str[r]==str[r-l+1])
                ++r;
            z[i]=r-l;
            --r;
        }
        else
        {
            int k=i-l+1;
            if(z[k]<r-i+1)
                z[i]=z[k];
            else
            {
                while(r<=n+n&&str[r]==str[r-i+1])
                    ++r;
                z[i]=r-(l=i);
                --r;
            }
        }
        //cout<<z[i]<<" ";
    }
    //cout<<'\n';
    pos=n+1;
    for(int i=n,l=0,r=0;i>=1;--i)
    {
        l=n-i+1,r=n-(pos-1)+1;
        int len=z[r+n];
        if(len<l-r+1)
        {
            if(str[len+1]>str[pos-len-1])
                pos=i;
        }
        else
        {
            len=pos-i;
            l=len+1,r=pos-1;
            if(str[z[l]+1]<str[z[l]+l])
                pos=i;
        }
    }
    tmp.clear();
    //cout<<pos<<'\n';
    for(int i=n;i>=pos;--i)
        tmp.push_back(str[i]);
    for(int i=1;i<pos;++i)
        tmp.push_back(str[i]);
    //cerr<<tmp<<'\n';
    if(tmp<res)
    {
        res=tmp;
        qwq=3;
    }
    pos=cnt;
    str=" "+t;
    while(pos>1)
    {
        bool flag=0;
        for(int i=a[pos-1].first,j=a[pos].first;i<=n;++i)
        {
            if(str[i]>str[j])
            {
                flag=1;
                break;
            }
            if(str[i]<str[j])
                break;
            if(j>=a[pos].first)
                ++j;
            else
                --j;
            if(j>n)
                j=a[pos].first-1;
        }
        if(flag)
            break;
        --pos;
    }
    pos=a[pos].first;
    tmp.clear();
    //cout<<pos<<'\n';
    for(int i=pos;i<=n;++i)
        tmp.push_back(str[i]);
    for(int i=pos-1;i>=1;--i)
        tmp.push_back(str[i]);
    //cerr<<tmp<<'\n';
    if(tmp<res)
    {
        res=tmp;
        qwq=4;
    }
    //cout<<qwq<<'\n';
    ans+=res;
    cout<<ans<<'\n';
    return 0;
}