#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N,d;int main(){cin>>T;while(T--){cin>>N>>d;For(i,1,N){int x;cin>>x;if(x%d==0||x>=d*10)cout<<"YES\n";else{int y=d;while(x-y>0&&(x-y)%10&&y<d*10)y+=d;if(x-y>0&&(x-y)%10==0)cout<<"YES\n";else cout<<"NO\n";}}}return 0;}