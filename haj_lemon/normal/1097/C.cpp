#include<bits/stdc++.h>
#define ll long long
#define INF 1e9
#define zh 500000
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int n,f[1000010],ansn;
int get(){
	string s;int no=0,pr=0;
	cin>>s;
	for (int i=0;i<s.length();i++){
		if (s[i]=='(')no++;
		if (s[i]==')'){
			if (no) no--;else pr++;
		}
	}
	if (pr&&no) return INF;
	return pr-no;
}
int main(){
	read(n);
	for (int i=1;i<=n;i++){int x=get();if (x!=INF) f[x+zh]++;}
	for (int i=0;i<zh;i++) ansn=ansn+min(f[i],f[zh*2-i]);
	ansn+=f[zh]/2;
	cout<<ansn<<endl;
	return 0;
}