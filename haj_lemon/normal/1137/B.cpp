#include<bits/stdc++.h>
#define ll long long
#define base1 7
#define base2 11
#define mo1 19260817
#define mo2 998244353
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
string s,t;
int a[3][4],m,n,fa[500010];
void wan(){
	while (a[0][0]){cout<<'0';a[0][0]--;}
	while (a[1][0]){cout<<'1';a[1][0]--;}
	puts("");
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>s;cin>>t;
	m=s.length();n=t.length();
	for (int i=0;i<m;i++) a[s[i]-'0'][0]++;
	fa[1]=0;
	for (int i=2;i<=n;i++){
		int x=fa[i-1];
		while (x!=0&&t[x]!=t[i-1]) x=fa[x];
		if (t[x]==t[i-1]) fa[i]=x+1;else fa[i]=0;
	}
	int no=fa[n];
	for (int i=no;i<n;i++) a[t[i]-'0'][2]++;
	for (int i=0;i<n;i++) a[t[i]-'0'][1]++;
	if (a[0][0]>=a[0][1]&&a[1][0]>=a[1][1]){
		cout<<t;a[0][0]-=a[0][1];a[1][0]-=a[1][1];
		while (a[0][0]>=a[0][2]&&a[1][0]>=a[1][2]){
			a[0][0]-=a[0][2];a[1][0]-=a[1][2];
			for (int i=no;i<n;i++) cout<<t[i];
		}
		wan();
	}else{
		wan();
	}
	return 0;
}
/*
111100000
1010
*/