#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
int T,N;bool check(int x){int y=sqrt(x);return (y-1)*(y-1)==x||y*y==x||(y+1)*(y+1)==x;}
int main(){cin>>T;while(T--){cin>>N;if(N&1){cout<<"NO\n";continue;}cout<<(check(N/2)||(N%4==0&&check(N/4))?"YES\n":"NO\n");}return 0;}