#include <bits/stdc++.h>
#define N 100005
using namespace std;
typedef long long ll;
string s;
int n,a,b,c;
void fail()
{
    cout<<"NO";
    exit(0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='a'&&(b||c))
            fail();
        if(s[i]=='b'&&(!a||c))
            fail();
        if(s[i]=='c'&&(!a||!b))
            fail();
        if(s[i]=='a')
            a++;
        if(s[i]=='b')
            b++;
        if(s[i]=='c')
            c++;
    }
    if(!a||!b||(c!=a&&c!=b))
        fail();
    cout<<"YES";
    return 0;
}