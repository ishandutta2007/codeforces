#include<iostream>
#include<cstdio>
#include<cstring>
#define N 100010
#define mod 1000000007
using namespace std;
int c[N],f[N],_2[N];
int main()
{
    int n;
    scanf("%d",&n);
    _2[0]=1;
    for(int i=1,a;i<=n;i++) scanf("%d",&a),c[a]++,_2[i]=_2[i-1]*2ll%mod;
    for(int i=N-10;i>=1;i--)
    {
        int s=0;
        for(int j=i;j<=N-10;j+=i) s+=c[j];
        f[i]=_2[s]-1;
        for(int j=i*2;j<=N-10;j+=i) f[i]=(f[i]-f[j]+mod)%mod;
    }
    printf("%d\n",f[1]);
    return 0;
}