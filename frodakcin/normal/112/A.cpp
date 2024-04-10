#include<bits/stdc++.h>
using namespace std;
int main(){
string a,b;
cin>>a>>b;
for(string*u: vector<string*>{&a,&b})
for(char& x:*u) if(x<'a') x+= 'a'- 'A';
if(a==b) cout<<0;
else if(a<b) cout<<-1; else cout<<1;}