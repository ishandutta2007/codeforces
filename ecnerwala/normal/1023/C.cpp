#include<bits/stdc++.h>
using namespace std;
int main(){
int n,k;string s;cin>>n>>k>>s;
k/=2;int v=0;
for(char c:s) {
if(c=='(') {if(k)k--,v++,cout<<c;}
else if(v) v--,cout<<c;
}
cout<<'\n';
}