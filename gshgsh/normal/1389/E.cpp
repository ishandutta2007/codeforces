#include<iostream>
using namespace std;
#define ll long long
int T,a,b,c;int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main(){cin>>T;while(T--)cin>>a>>b>>c,a=min(a,b),c/=GCD(b-1,c),cout<<1ll*a%c*(a/c+1)*(a/c)/2+1ll*(c-a%c)*(a/c)*(a/c-1)/2<<endl;return 0;}