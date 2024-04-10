#include<iostream>
using namespace std;
int T,a,b,N;int main(){cin>>T;while(T--){cin>>a>>b>>N;int cnt=1;while(a%2==0){a>>=1,cnt<<=1;if(cnt>=N)break;}while(b%2==0){b>>=1,cnt<<=1;if(cnt>=N)break;}cout<<(cnt>=N?"YES\n":"NO\n");}return 0;}