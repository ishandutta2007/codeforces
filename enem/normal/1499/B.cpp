#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;

        int n = s.size();

        bool nx = false;
        bool bk = false;
        bool bad = false;

        for(int i=0; i<n; i++)
        {
            if(!nx && s[i]=='0')
            {
                bk = false;
            }
            else if(!nx && s[i]=='1' && bk)
            {
                nx = true;
                bk = false;
            }
            else if(!nx && s[i]=='1' && !bk)
            {
                bk = true;
            }
            if(nx && s[i]=='1')
            {
                bk = false;
            }
            else if(nx && s[i]=='0' && !bk)
            {
                bk = true;
            }
            else if(nx && s[i]=='0' && bk)
            {
                bad = true;
            }
        }

        if(!bad) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}