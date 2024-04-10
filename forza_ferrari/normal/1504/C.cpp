#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,x,y,cnt;
string s,a,b;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>s;
        a.clear();
        b.clear();
        x=y=cnt=0;
        for(register int i=0;i<n;++i)
        {
            if(s[i]=='1')
                ++x;
            else
                ++y;
        }
        if((y&1)||(x&1)||s[0]=='0'||s[n-1]=='0')
        {
            puts("NO");
            continue;
        }
        bool tag=0;
        for(register int i=0;i<n;++i)
        {
            if(s[i]=='1')
            {
                ++cnt;
                if(cnt<=(x>>1))
                {
                    a.push_back('(');
                    b.push_back('(');
                }
                else
                {
                    a.push_back(')');
                    b.push_back(')');
                }
            }
            else
            {
                if(tag)
                {
                    a.push_back(')');
                    b.push_back('(');
                }
                else
                {
                    a.push_back('(');
                    b.push_back(')');
                }
                tag^=1;
            }
        }
        puts("YES");
        cout<<a<<endl<<b<<endl;
    }
    return 0;
}