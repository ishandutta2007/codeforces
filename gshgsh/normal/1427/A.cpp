#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 51
int T,N,a[MAXN],s;int main(){cin>>T;while(T--){cin>>N,s=0;For(i,1,N)cin>>a[i],s+=a[i];if(!s){cout<<"NO\n";continue;}cout<<"YES\n";s>0?sort(a+1,a+N+1,greater<int>()):sort(a+1,a+N+1);For(i,1,N)cout<<a[i]<<' ';cout<<endl;}return 0;}