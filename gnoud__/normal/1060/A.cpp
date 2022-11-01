#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,res=0;cin>>n;
    for(int i=1;i<=n;++i) 
    {char c;cin>>c;if(c=='8') res++;}
cout<<min(n/11,res);
}