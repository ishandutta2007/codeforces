#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
int T;ll p,a,b,c;
int main(){cin>>T;while(T--)cin>>p>>a>>b>>c,cout<<min((p+a-1)/a*a-p,min((p+b-1)/b*b-p,(p+c-1)/c*c-p))<<endl;return 0;}