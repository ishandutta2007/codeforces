#include <iostream>
using namespace std;int n,a,x,z,i;int G(int a,int b){return b?G(b,a%b):a;}main(){for(cin>>n;++i<=n;z=G(z,a))cin>>a,x=a>x?a:x;cout<<((x/z - n)%2?"Alice":"Bob");}
//compress your code!