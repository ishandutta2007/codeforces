#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
ll ansn;
string s;
bool pa(int l,int r){
	for (int i=l;i<=r-2;i++)
		for (int k=1;i+k*2<=r;k++)if (s[i-1]==s[i+k-1]&&s[i-1]==s[i+k+k-1])return 1;
	return 0;
}
int main(){
	cin>>s;
	int l=s.length();
	for (int i=9;i<=l;i++)ansn+=(l-i+1);
	for (int i=3;i<=8;i++)
		for (int j=1;j+i-1<=l;j++)if (pa(j,i+j-1))ansn++;
	cout<<ansn<<endl;
	return 0;
}