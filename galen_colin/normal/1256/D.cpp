/* testing code for pikafan_8080 */

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i = 0 ; i < t; i++)
    {
        long long n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int p = 0 ;
        for(int j = 0 ; j < s.size(); j++)
        {
            if(s[j] == '1')
            {
                continue;
            }
            else
            {
                int moves_req = j - p;
                if(moves_req <= k)
                {
                    s[j] = '1';
                    s[p] = '0';
                    k = k - (j - p);
                    p = p + 1;
                }
                else
                {
                    s[j] = '1';
                    s[j-k] = '0';
                    break;
                }
            }
        }
        cout<<s<<"\n";
    }
    return 0;
}