#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[5001],ans,sum[5001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        ans=0;
        for(int i=1;i<=n;++i)
        {
            int cnt=0,lst=0,len=0,maxn=0;
            for(int j=1;j<=n;++j)
                if(a[j]==i)
                {
                    int tmp=0,qwq=0,pos=j;
                    while(pos<=n&&a[pos]==i)
                    {
                        ++tmp;
                        ++pos;
                    }
                    qwq=tmp;
                    if(maxn>len/2)
                        tmp-=maxn-(len-maxn);
                    else
                        tmp-=len&1;
                    if(tmp>0)
                    {
                        cnt+=tmp;
                        len=maxn=0;
                        for(int k=lst+1;k<j;++k)
                            --sum[a[k]];
                        j=lst=pos-1;
                    }
                    else
                    {
                        len+=qwq;
                        maxn=max(maxn,sum[i]+=qwq);
                        j=pos-1;
                    }
                }
                else
                {
                    ++len;
                    maxn=max(maxn,++sum[a[j]]);
                }
            if(maxn>len/2)
                cnt-=maxn-(len-maxn);
            else
                cnt-=len&1;
            len=maxn=0;
            for(int k=lst+1;k<=n;++k)
                --sum[a[k]];
            ans=max(ans,cnt);
        }
        cout<<ans<<'\n';
    }
    return 0;
}