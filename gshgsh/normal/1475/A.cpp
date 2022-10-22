#include<iostream>
using namespace std;
int T;long long N;int main(){cin>>T;while(T--){cin>>N;while(N>1)if(N&1)break;else N>>=1;cout<<(N>1?"YES\n":"NO\n");}return 0;}