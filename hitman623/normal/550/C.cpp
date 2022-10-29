#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    s.pb('0');
    s.pb('0');
    reverse(s.begin(),s.end());
    long n=s.length(),i,a[126][3],l,num,j;
    for(i=0;i<125;++i)
    {
        num=i*8;
        a[i][2]=num%10;
        num/=10;
        a[i][1]=num%10;
        num/=10;
        a[i][0]=num%10;
    }
    for(i=0;i<125;++i)
    {
        l=0;
        for(j=0;j<n;++j)
        {
            if(a[i][l]==s[j]-'0') l++;
            if(l==3) break;
        }
        if(l==3)
        {
            cout<<"YES\n";
            if(a[i][0])cout<<a[i][0];
            if(a[i][1])cout<<a[i][1];
            cout<<a[i][2];
            exit(0);
        }
    }
    cout<<"NO";
    return 0;
}