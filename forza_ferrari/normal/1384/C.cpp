#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int t,n,ans;
string s1,s2;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        cin>>s1>>s2;
        bool flag=1;
        for(register int i=0;i<n;++i)
            if(s1[i]>s2[i])
            {
                puts("-1");
                flag=0;
                break;
            }
        if(!flag)
            continue;
        for(register char i='a';i<='t';++i)
        {
            if(s1==s2)
                break;
            char minn='u';
            for(register int j=0;j<n;++j)
                if(s1[j]==i&&s1[j]!=s2[j])
                    minn=min(minn,s2[j]);
            if(minn=='u')
                continue;
            ++ans;
            for(register int j=0;j<n;++j)
                if(s1[j]==i&&s1[j]!=s2[j])
                    s1[j]=minn;
        }
        cout<<ans<<endl;
    }
    return 0;
}