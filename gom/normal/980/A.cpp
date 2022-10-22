#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;int a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='-')
            a++;
        else
            b++;
    }
    if(b&&a%b)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}