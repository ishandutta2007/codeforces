//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
string s;
int main()
{
    cin>>n;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        for(int j=1;j<s.size();j++)
        {
            bool ok=1;
            if(i+j*4>=s.size())continue;
            for(int k=0;k<=4;k++)
            {
                if(s[i+j*k]=='.')
                {
                    ok=0;
                    break;
                }
            }
            if(ok)
            {
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
    return 0;
}