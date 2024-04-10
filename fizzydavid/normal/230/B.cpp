#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std; 
set<long long>a;
bool isp[1000050];
long long n,x;
int main()
{
    for(int i=2;i<=1000000;i++)
    {
        if(!isp[i])
        {
            a.insert((long long)i*i);
            for(int j=i*2;j<=1000000;j+=i)isp[j]=1;
        }
    }
    cin>>n;
    while(n--)
    {
        cin>>x;if(a.count(x))cout<<"YES";else cout<<"NO";
        cout<<endl;
    } 
    return 0;
}