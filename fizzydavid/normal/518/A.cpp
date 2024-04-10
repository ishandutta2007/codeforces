//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
string a,b,t;
int main()
{
    cin>>a>>b;
    if(a.size()>b.size())
    {
        puts("No such string");
        return 0;
    }
    int i=a.size()-1,j=b.size()-1;
    while(i>=0&&a[i]=='z')i--;
    while(j>=0&&b[j]=='a')j--;
    if(i==-1&&j==-1)
    {
        if(a.size()+1>=b.size())
        {
            puts("No such string");
            return 0;
        }
        for(int i=0;i<=a.size();i++)cout<<'a';
    }
    else
    {
        if(i!=-1)
        {
            a[i]++;
            for(int k=i+1;k<a.size();k++)a[k]='a';
            if(a>=b)
            {
                puts("No such string");
                return 0;
            }
            cout<<a<<endl;
        }
        else
        {
            b[j]--;
            for(int k=j+1;k<b.size();k++)b[k]='z';
            if(a>=b)
            {
                puts("No such string");
                return 0;
            }
            cout<<b<<endl;
        }
    }
    return 0;
}