#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,M;double p[MAXN],ans;double pow(double a,int b){double ans=1;while(b)b&1?ans*=a:0,a*=a,b>>=1;return ans;}
int main(){cin>>M>>N;For(i,1,M)p[i]=pow(i*1.0/M,N);For(i,1,M)ans+=i*(p[i]-p[i-1]);printf("%.6lf",ans);return 0;}