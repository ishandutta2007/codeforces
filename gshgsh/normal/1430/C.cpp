#include<iostream>
using namespace std;
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N;int main(){cin>>T;while(T--){cin>>N;cout<<2<<endl;cout<<N<<' '<<N-1<<endl;FOR(i,N-2,1)cout<<i+2<<' '<<i<<endl;}return 0;}