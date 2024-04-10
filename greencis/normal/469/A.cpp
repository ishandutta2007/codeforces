#include <bits/stdc++.h>
using namespace std;
int n,p,q,x,u[10000],c;
int main(){
cin>>n;
for(int i=0;cin>>p,i<2;++i)
while(p--){
cin>>x;
if(!u[x])++c;
u[x]=1;
}
if(c==n)cout<<"I become the guy.";
else cout<<"Oh, my keyboard!";
}