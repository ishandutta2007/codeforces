#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
int n,m,len,val[201],a[31],b[31];
bool vis[401],tag[401];
vector<int> v[401],node;
string s;
inline bool dfs(int k)
{
    if(vis[k<=n? k+n:k-n])
        return 0;
    if(vis[k])
        return 1;
    vis[k]=1;
    node.emplace_back(k);
    for(int i:v[k])
        if(!vis[i]&&!dfs(i))
            return vis[k]=0;
    return 1;
}
inline void clear()
{
    for(int i:node)
        vis[i]=0;
    node.clear();
}
int main()
{
    cin>>s;
    len=s.length();
    s=" "+s;
    a[len+1]=b[len+1]=len+1;
    int lst1=len+1,lst2=len+1;
    for(int i=len;i>=1;--i)
    {
        if(s[i]=='V')
            lst1=i;
        else
            lst2=i;
        a[i]=lst1;
        b[i]=lst2;
    }
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        char cx,cy;
        cin>>x>>cx>>y>>cy;
        v[cx=='C'? x:x+n].emplace_back(cy=='C'? y:y+n);
        v[cy=='C'? y+n:y].emplace_back(cx=='C'? x+n:x);
    }
    for(int i=1;i<=n;++i)
    {
        clear();
        if(!dfs(i))
        {
            clear();
            if(!dfs(i+n))
            {
                cout<<"-1\n";
                return 0;
            }
            tag[i+n]=1;
        }
        else
        {
            clear();
            if(!dfs(i+n))
                tag[i]=1;
        }
    }
    for(int i=1;i<=n+n;++i)
        vis[i]=tag[i];
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;++i)
        val[i]=s[i]-'a'+1;
    bool flag=0;
    for(int i=1;i<=n;++i)
    {
        node.clear();
        if(flag)
            val[i]=1;
        oh:;
        if(a[val[i]]>len)
        {
            if(b[val[i]]>len||vis[i+n]||!dfs(i))
            {
                cout<<"-1\n";
                return 0;
            }
        }
        else if(b[val[i]]>len)
        {
            if(vis[i]||!dfs(i+n))
            {
                cout<<"-1\n";
                return 0;
            }
        }
        else if(!vis[i]&&!vis[i+n])
        {
            if(a[val[i]]>b[val[i]])
            {
                if(!dfs(i))
                {
                    flag=1;
                    if(!dfs(i+n))
                    {
                        cout<<"-1\n";
                        return 0;
                    }
                }
            }
            else
            {
                if(!dfs(i+n))
                {
                    flag=1;
                    if(!dfs(i))
                    {
                        cout<<"-1\n";
                        return 0;
                    }
                }
            }
        }
        else if(vis[i])
        {
            if(b[val[i]]>val[i])
                flag=1;
        }
        else
        {
            if(a[val[i]]>val[i])
                flag=1;
        }
        if(!flag)
        {
            for(int j=i+1;j<=n;++j)
                if(vis[j])
                {
                    if(b[val[j]]>len)
                    {
                        flag=1;
                        ++val[i];
                        break;
                    }
                    if(b[val[j]+1]<=len)
                        break;
                }
                else if(vis[j+n])
                {
                    if(a[val[j]]>len)
                    {
                        flag=1;
                        ++val[i];
                        break;
                    }
                    if(a[val[j]+1]<=len)
                        break;
                }
                else if(a[val[j]+1]<=len||b[val[j]+1]<=len)
                    break;
            if(flag)
            {
                clear();
                goto oh;
            }
        }
        
    }
    for(int i=1;i<=n;++i)
        cout<<(char)(vis[i]? b[val[i]]+'a'-1:a[val[i]]+'a'-1);
    cout<<'\n';
    return 0;
}