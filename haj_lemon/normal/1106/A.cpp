#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
int n,ansn;
char ch[510][519];
int main(){
	read(n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)cin>>ch[i][j];
	for (int i=2;i<n;i++)
		for (int j=2;j<n;j++) if (ch[i][j]=='X'&&ch[i-1][j-1]=='X'&&ch[i+1][j-1]=='X'&&ch[i-1][j+1]=='X'&&ch[i+1][j+1]=='X') ansn++;
	cout<<ansn<<endl;
	return 0;
}