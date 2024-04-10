#include <bits/stdc++.h>

using namespace std;

string s1,s2;
int a,b,c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s1>>s2;
    a = ((s1[0]-'0')*10+s1[1]-'0')*60;
    a+= (s1[3]-'0')*10+s1[4]-'0';
    b = ((s2[0]-'0')*10+s2[1]-'0')*60;
    b+= (s2[3]-'0')*10+s2[4]-'0';
    c = a+(b-a)/2;
    if(c/60<10) cout<<"0";
    cout<<c/60<<":";
    if(c%60<10) cout<<"0";
    cout<<c%60;
    return 0;
}