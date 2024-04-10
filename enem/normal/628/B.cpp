#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    string s;
    cin>>s;

    int n = s.size();
    long long ans = 0;
    for(int i=0; i<n; i++)
    {
        if( i>0 && (s[i]-'0') % 4 == 0 && (s[i-1]-'0') % 2 == 0)
        {
            ans += i+1;
        }
        else if( (s[i]-'0') % 4 == 0 )
        {
            ans++;
        }
        else if( i>0 && (s[i]-'0') % 2 == 0 && (s[i-1]-'0') % 2 == 1)
        {
            ans += i;
        }
    }
    cout<<ans;

    return 0;
}