#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,x,sum,cnt;int main(){cin>>T;while(T--){cin>>x,sum=cnt=0;For(i,1,x){sum+=i;cnt++;if(sum>=x)break;}cout<<cnt+(sum==x+1)<<endl;}return 0;}