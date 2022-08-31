#include<bits/stdc++.h>
#define R(X,Y) X=(X+Y)%P;
int64_t g[410],n,P,k,a,f;int main(){std::cin>>n>>P;g[0]=f=k=1;for(--n;n>=0;n-=2,++k){for(int i=1;i<=n;++i)R(g[i],g[i-1]*k*2)f=f*k%P;R(a,g[n]*f)}printf("%d\n",a);}