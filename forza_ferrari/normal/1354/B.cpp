#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,lst[4],ans;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        s=" "+s;
        ans=1e9;
        lst[1]=lst[2]=lst[3]=0;
        for(int i=1;i<=n;++i)
        {
            lst[s[i]-'0']=i;
            int val=min(lst[1],min(lst[2],lst[3]));
            if(val)
                ans=min(ans,i-val+1);
        }
        cout<<(ans==1e9? 0:ans)<<'\n';
    }
    return 0;
}