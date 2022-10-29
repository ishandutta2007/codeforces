#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,i,d;
    string s;
    vector < long > digits;
    cin>>n;
    cin>>s;
    for(i=0;i<n;++i)
    {
        d=s[i]-'0';
        if(d==4) {digits.pb(2);digits.pb(2);digits.pb(3);}
        else if(d==6) {digits.pb(3);digits.pb(5);}
        else if(d==8) {digits.pb(2);digits.pb(2);digits.pb(2);digits.pb(7);}
        else if(d==9) {digits.pb(3);digits.pb(3);digits.pb(2);digits.pb(7);}
        else digits.pb(d);
    }
    sort(digits.begin(),digits.end());
    n=digits.size();
    for(i=n-1;i>=0;i--)
    {
        if(digits[i]>1)
        cout<<digits[i];
        else break;
    }
    return 0;
}