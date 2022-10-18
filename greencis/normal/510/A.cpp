#include <bits/stdc++.h>
using namespace std;
int n,m;
char s[999][999];
int main(){ios_base::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<n;++i,cout<<"\n")
for(int j=0;j<m;++j)
if(i%2==0||i%4==1&&j==m-1||i%4==3&&j==0)cout<<"#";else cout<<".";
}