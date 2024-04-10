#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 200001
int N,a[MAXN],pw[MAXN],mul[MAXN],su[MAXN],Su[MAXN],ans;
int main()
{
	string s;cin>>s;N=s.length();For(i,1,N)a[i]=s[i-1]-'0';mul[0]=pw[0]=1;For(i,1,N)pw[i]=pw[i-1]*10ll%P,mul[i]=(mul[i-1]+pw[i])%P;
	FOR(i,N,1)su[i]=(su[i+1]+1ll*a[i]*pw[N-i])%P,Su[i]=(Su[i+1]+su[i])%P;
	int sum=0;For(i,0,N-1)ans=(ans+1ll*mul[N-1-i]*sum+Su[i+2])%P,sum=(sum*10ll+a[i+1])%P;cout<<ans<<endl;return 0;
}