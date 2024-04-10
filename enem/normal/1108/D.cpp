#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    char a[3]={'R','G','B'};
    int ans=0;
    for(int i=1;i<n;i++)
    {
        int k,l,t;
        for(int j=0;j<3;j++)
        {
            if(s.at(i-1)==a[j]) k=j;
            if(s.at(i)==a[j]) t=j;
            if(i==n-1) l=k;
            else
            {
                if(s.at(i+1)==a[j]) l=j;
            }
        }
        if(t==k)
        {
            if((k+1)%3==l) s.at(i)=a[(k+2)%3];
            else s.at(i)=a[(k+1)%3];
            ans++;
        }
    }
    cout<<ans<<'\n'<<s;
    return 0;
}