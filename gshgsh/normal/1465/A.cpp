#include<iostream>
#include<string>
using namespace std;
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int T,N;string a;
int main(){cin>>T;while(T--){cin>>N>>a;int cnt=0;FOR(i,N-1,0)if(a[i]==')')cnt++;else break;cout<<(cnt>N/2?"Yes\n":"No\n");}return 0;}