
#include <bits/stdc++.h>
using namespace std;
int n,m;char a[100000];
int main(){
cin>>n>>m;
for(int i=1;i<=n;i++){cin>>a[i];}
for(int i=1;i<=m;i++){
for(int i=1;i<=n;i++){if(a[i]=='B'&&a[i+1]=='G'){a[i+1]='B';a[i]='G';i++;}}
}
for(int i=1;i<=n;i++){cout<<a[i];}
return 0;
}