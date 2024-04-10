#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(k==0) cout<<s;
    else if(n==1) cout<<0;
    else
    {
         ll i=0;
         while(k!=0&&i<n)
         {
              if(i==0)
              {
                  if(s[i]!='1')
                  {
                       s[i]='1';
                       k--;
                  }
              }
              else
              {
                  if(s[i]!='0')
                  {
                       s[i]='0';
                       k--;
                  }
              }
              i++;
         }
         cout<<s;
    }

    return 0;
}