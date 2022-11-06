#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
char s[N];
int n;
int F(int i){
  if(i<2)return 0;
  return s[i]=='c'&&s[i-1]=='b'&&s[i-2]=='a';
}
int main(){
#ifdef flukehn
  freopen("a.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0);
  int Q;
  cin>>n>>Q;
  cin>>s;
  int tot=0;
  for(int i=2;i<n;++i)
    tot+=F(i);
  while(Q--){
    int x;
    char c;
    cin>>x>>c;
    --x;
    tot-=F(x)+F(x+1)+F(x+2);
    s[x]=c;
    tot+=F(x)+F(x+1)+F(x+2);
    cout<<tot<<"\n";
  }
}