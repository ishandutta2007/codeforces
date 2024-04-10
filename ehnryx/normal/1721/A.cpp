#include<bits/stdc++.h>
using namespace std;
int main(int T,char**){cin>>T;
while(T--){char a[4];for(int i=0;i<4;i++){
  cin>>a[i];
}
set<char>s(begin(a),end(a));
cout<<size(s)-1<<'\n';
}
return 0;}