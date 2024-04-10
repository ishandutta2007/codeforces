#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,ans0,ans1,cnt0,cnt1,cnt2,cnt3;
string a,b;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        ans0=ans1=cnt0=cnt1=cnt2=cnt3=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]==b[i])
            {
                ++ans0;
                if(a[i]=='0')
                    ++cnt0;
                else
                    ++cnt1;
            }
            else
            {
                ++ans1;
                if(a[i]=='0')
                    ++cnt2;
                else
                    ++cnt3;
            }
        }
        if(ans1%2!=0||cnt2!=cnt3)
            ans1=n+1;
        if(ans0%2==0||cnt1-cnt0!=1)
            ans0=n+1;
        cout<<(min(ans0,ans1)==n+1? -1:min(ans0,ans1))<<endl;
    }
    return 0;
}