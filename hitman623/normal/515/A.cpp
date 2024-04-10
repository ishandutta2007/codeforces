#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long long a,b,s;
    cin>>a>>b>>s;
    a=abs(a);
    b=abs(b);
    if(s<a+b) {cout<<"NO";exit(0);}
    if((s-a-b)%2) {cout<<"NO";exit(0);}
    cout<<"YES";
    return 0;
}