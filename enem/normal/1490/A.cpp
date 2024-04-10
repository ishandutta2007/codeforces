#include <iostream>
int main(){int t,n,p,c,a;std::cin>>t;while(t--){std::cin>>n>>p;a=0;while(--n){std::cin>>c;if(c-p) a+=31-__builtin_clz((p+c-1)/(p>c?c:p)-1);p=c;}std::cout<<a<<'\n';}}