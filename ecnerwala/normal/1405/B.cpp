#include<bits/stdc++.h>
using std::cin;int64_t T,N,a,c,v;main(){for(cin>>T;cin>>N;std::cout<<a<<' ')for(a=c=0;N--;a=std::max(a,c-=v))cin>>v;}