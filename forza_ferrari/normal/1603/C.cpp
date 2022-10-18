#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int mod=998244353;
int t,n,a[100001],ans,cnt[2][100001];
vector<int> v[2];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
int main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;++i)
            a[i]=read();
        ans=0;
        v[0].clear();
        v[1].clear();
        int now=0;
		for(int i=n;i;--i)
		{
            now^=1;
            v[now].clear();
			for(int j:v[now^1])
			{
                int pos=(a[i]-1)/j;
				ans=(ans+1ll*cnt[now^1][j]*pos%mod*i)%mod;
                if(!cnt[now][a[i]/(pos+1)])
                    v[now].push_back(a[i]/(pos+1));
				cnt[now][a[i]/(pos+1)]+=cnt[now^1][j];
                cnt[now^1][j]=0;
			}
            if(!cnt[now][a[i]])
                v[now].push_back(a[i]);
            ++cnt[now][a[i]];
		}
        for(int i:v[now])
            cnt[now][i]=0;
        printf("%d\n",ans);
    }
    return 0;
}