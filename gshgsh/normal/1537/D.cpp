#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 301
int T,N,f[MAXN];
bool check(int x){int i=0;while((1<<i)<x)i++;if((1<<i)!=x)return 0;return i&1;}
int main()
{
    cin>>T;For(i,1,255){for(int j=2;j*j<=i;j++)if(i%j==0)f[i]|=!f[i-j],f[i]|=!f[i-i/j];}
    while(T--)
    {
        cin>>N;if(N<256){cout<<(f[N]?"Alice\n":"Bob\n");continue;}
        if(check(N)){cout<<"Bob\n";continue;}cout<<(N&1?"Bob\n":"Alice\n");
    }
    return 0;
}