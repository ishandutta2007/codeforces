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
string s;
int a[1000100];
int p,x;
int main()
{
    cin>>p>>x;
    for(a[1]=1;a[1]<=9;a[1]++)
    {
        int c=0;
        for(int i=2;i<=p;i++)
        {
            a[i]=a[i-1]*x+c;
            c=a[i]/10;
            a[i]=a[i]%10;
        }
        if(a[1]==c+a[p]*x%10&&a[p]!=0&&a[p]<=9/x)
        {
            for(int i=p;i>=1;i--)
            {
                cout<<a[i];
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<"Impossible";
    return 0;
}