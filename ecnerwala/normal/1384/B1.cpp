#include<iostream>
using std::cin;int64_t T,N,K,L,t,d,a;main(){for(cin>>T;T--;puts(a?"No ":"Yes "))for(a=t=0,cin>>N>>K>>L;N--;d-=L,t*=d>-K,t=std::max(t,K+d),a|=d+t++>K)cin>>d;}