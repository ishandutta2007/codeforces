#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
char s[3010][3010],S[3010][3010];
char kmp[3010],ans[3010];
LL L[3010];
LL N,i,j;
LL l[3010],r[3010];
LL x;
bool flag;
vector<LL>pi;
inline LL KMP(char*X,LL len,char*s)
{
    LL i,j;
    for(i=j=0;i<len;i++)
    {
        while(j>0&&X[i]!=s[j])
            j=pi[j-1];
        if(X[i]==s[j])
            j++;
        if(j==pi.size())
            return i;
    }
    return -1;
}
inline void getpi(char*X,LL len)
{
    pi.clear();
    pi.resize(len);
    LL i,j;
    for(i=j=0;++i<len;)
    {
        while(j>0&&X[i]!=X[j])
            j=pi[j-1];
        if(X[i]==X[j])
            pi[i]=++j;
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=0;i<N;i++)
        cin>>s[i];
    for(i=0;i<N;i++)
        cin>>S[i];
    for(i=0;i<N;i++)
    {
        L[i]=strlen(s[i]);
        for(l[i]=0;l[i]<L[i];l[i]++)
            if(s[i][l[i]]!=S[i][l[i]])
                break;
        for(r[i]=L[i];r[i]-->0;)
            if(s[i][r[i]]!=S[i][r[i]])
                break;
    }
    for(x=0;x<N;x++)
        if(l[x]<=r[x])
            break;
    if(x==N)
    {
        cout<<"YES"<<endl;
        cout<<'a'<<endl;
        cout<<'a'<<endl;
        return 0;
    }
    for(i=x+1;i<N;i++)
        if(r[i]-l[i]!=r[x]-l[x]&&l[i]<=r[i])
            return cout<<"NO"<<endl,0;
    for(i=x+1;i<N;i++)
    {
        if(l[i]>r[i])
            continue;
        for(j=0;j<=r[x]-l[x];j++)
            if(s[i][j+l[i]]!=s[x][j+l[x]]||S[i][j+l[i]]!=S[x][j+l[x]])
                return cout<<"NO"<<endl,0;
    }
    flag=true;
    while(flag)
    {
        if(l[x]==0)
            break;
        for(i=x+1;i<N;i++)
        {
            if(l[i]>r[i])
                continue;
            if(l[i]==0||s[i][l[i]-1]!=s[x][l[x]-1]||S[i][l[i]-1]!=S[x][l[x]-1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            for(i=0;i<N;i++)
                if(l[i]<=r[i])
                    l[i]--;
    }
    flag=true;
    while(flag)
    {
        if(r[x]==L[x]-1)
            break;
        for(i=x+1;i<N;i++)
        {
            if(l[i]>r[i])
                continue;
            if(r[i]==L[i]-1||s[i][r[i]+1]!=s[x][r[x]+1]||S[i][r[i]+1]!=S[x][r[x]+1])
            {
                flag=false;
                break;
            }
        }
        if(flag)
            for(i=0;i<N;i++)
                if(l[i]<=r[i])
                    r[i]++;
    }
    for(i=l[x];i<=r[x];i++)
    {
        kmp[i-l[x]]=s[x][i];
        ans[i-l[x]]=S[x][i];
    }
    getpi(kmp,r[x]-l[x]+1);
    for(i=0;i<N;i++)
    {
        if(l[i]>r[i])
        {
            if(KMP(s[i],L[i],kmp)!=-1)
                return cout<<"NO"<<endl,0;
        }
        else
        {
            if(KMP(s[i],L[i],kmp)!=r[i])
                return cout<<"NO"<<endl,0;
        }
    }
    cout<<"YES"<<endl;
    cout<<kmp<<endl;
    cout<<ans<<endl;
    return 0;
}