#include<bits/stdc++.h>
using namespace std;int64_t N,M,a;main(){for(cin>>N;cin>>N>>M;cout<<a<<' '){vector<int>W(M),C(M);for(;N--;++W[--a])cin>>a;for(int&c:C)cin>>c;for(a=0;M--;)for(;W[M]--;)a+=C[min(M,++N)];}}