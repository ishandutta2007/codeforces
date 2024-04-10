#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 10001
int a[MAXN],b[MAXN],c[MAXN],x[MAXN],y[MAXN],z[MAXN],pos[MAXN];
int main()
{
	string s;cin>>s;int N=s.length();For(i,0,N-1)a[i]=i%26,b[i]=i/26%26,c[i]=i/26/26;
	cout<<"? ";For(i,0,N-1)cout<<char(a[i]+'a');cout<<endl;For(i,0,N-1){char c;cin>>c;x[i]=c-'a';}
	cout<<"? ";For(i,0,N-1)cout<<char(b[i]+'a');cout<<endl;For(i,0,N-1){char c;cin>>c;y[i]=c-'a';}
	cout<<"? ";For(i,0,N-1)cout<<char(c[i]+'a');cout<<endl;For(i,0,N-1){char c;cin>>c;z[i]=c-'a';}
	For(i,0,N-1)pos[x[i]+y[i]*26+z[i]*26*26]=i;cout<<"! ";For(i,0,N-1)cout<<s[pos[i]];cout<<endl;return 0;
}