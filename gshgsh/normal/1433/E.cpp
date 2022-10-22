#include<iostream>
using namespace std;
#define ull unsigned long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int main(){int N;cin>>N;ull ans=1;For(i,2,N/2-1)ans*=i;For(i,N/2+1,N-1)ans*=i;cout<<ans<<endl;return 0;}