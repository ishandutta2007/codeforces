#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,x,y;
int main(){cin>>T;while(T--){cin>>x>>y;int cnt=0;bool flag=x<=y;For(i,0,29){cnt+=(x>>i)&1,cnt-=(y>>i)&1;if(cnt<0){flag=0;break;}}cout<<(flag?"YES\n":"NO\n");}return 0;}