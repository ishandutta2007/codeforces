#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,ans,sum,l,r;
string s;
int main()
{
    scanf("%d",&n);
    if(n&1)
    {
        puts("-1");
        return 0;
    }
    cin>>s;
    for(register int i=0;i<n;++i)
    {
        r+=s[i]==')';
        if(r>l)
            ++sum;
        else
        {
            ans+=sum;
            sum=0;
        }
        l+=s[i]=='(';
    }
    ans+=sum;
    printf("%d\n",l^r? -1:ans);
    return 0;
}