#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int N,a[MAXN],s[MAXN],pos[MAXN],type,id,pre;
int main()
{
	cin>>N;For(i,2,N){cout<<"XOR "<<1<<' '<<i<<endl,cin>>s[i];if(!s[i])type=1,id=i;if(pos[s[i]])type=2,id=i,pre=pos[s[i]];pos[s[i]]=i;}
	if(type==1){cout<<"AND "<<1<<' '<<id<<endl,cin>>a[1];cout<<"! "<<a[1]<<' ';For(i,2,N)cout<<(s[i]^a[1])<<' ';return 0;}
	if(type==2){cout<<"AND "<<pre<<' '<<id<<endl,cin>>a[id],a[1]=s[id]^a[id];cout<<"! "<<a[1]<<' ';For(i,2,N)cout<<(s[i]^a[1])<<' ';return 0;}
	For(i,2,N){int x;if(s[i]==1)cout<<"AND "<<1<<' '<<i<<endl,cin>>x,a[1]|=x;if(s[i]==2)cout<<"AND "<<1<<' '<<i<<endl,cin>>x,a[1]|=x&1;}
	cout<<"! "<<a[1]<<' ';For(i,2,N)cout<<(s[i]^a[1])<<' ';return 0;
}