#include<bits/stdc++.h>
using namespace std;
long long n,a,b,c,m,M;
int main(){scanf("%d",&n);for(int i=0;i<n;++i) scanf("%lld",&a),((i==0)?M=-a,m=a:b=max({c,M+a,m-a}),M=max(M,c-a),m=max(m,c+a),c=b);printf("%lld",b);}