#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,a[MAXN],s[MAXN],s1,s2,s3;
int main()
{
	cin>>N;For(i,2,N)cout<<"XOR "<<1<<' '<<i<<endl,cin>>s[i];cout<<"AND "<<2<<' '<<3<<endl,cin>>s1;cout<<"AND "<<1<<' '<<3<<endl,cin>>s2;cout<<"AND "<<1<<' '<<2<<endl,cin>>s3;
	cout<<"! "<<(a[1]=s2+s3-s1+(s[2]+s[3]-(s[2]^s[3])>>1))<<' ';For(i,2,N)cout<<(s[i]^a[1])<<' ';return 0;
}