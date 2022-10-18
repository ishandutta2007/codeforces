#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int t,ans;
vector<int> v;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>s;
        int len=s.length();
        v.clear();
        for(register int i=1;i<len-1;++i)
        {
            if((s[i-1]=='o'&&s[i]=='n'&&s[i+1]=='e')||(s[i-1]=='t'&&s[i]=='w'&&s[i+1]=='o'))
            {
                ++ans;
                v.push_back(i);
                if(i<3)
                    continue;
                if(s[i-3]=='t'&&s[i-2]=='w'&&s[i-1]=='o'&&s[i]=='n'&&s[i+1]=='e')
                {
                    --ans;
                    v.pop_back();
                    v.pop_back();
                    v.push_back(i-1);
                }
            }
        }
        printf("%d\n",ans);
        for(register int i=0;i<ans;++i)
            printf("%d ",v[i]+1);
        puts("");
    }
    return 0;
}