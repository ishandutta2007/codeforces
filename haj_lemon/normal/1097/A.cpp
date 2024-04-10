#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
string s1,s;
bool ans=0;
int main(){
	cin>>s1;
	for (int i=1;i<=5;i++){cin>>s;if (s[0]==s1[0]||s[1]==s1[1]) ans=1;}
	if (ans) puts("YES");else puts("NO");
	return 0;
}