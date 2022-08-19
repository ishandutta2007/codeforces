#include<bits/stdc++.h>
int N,K,i,j;main(){for(std::cin>>N;std::cin>>N>>K;)for(puts(K%N?"2 ":"0 "),i=N;i--;puts(" "))for(j=N;j--;std::cout<<((j+i)%N*N+i<K));}