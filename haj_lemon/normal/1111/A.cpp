#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
string s1,s2;
bool pa(char x){
	if (x=='a'||x=='u'||x=='i'||x=='o'||x=='e') return 1;return 0;
}
int main(){
	cin>>s1>>s2;
	int l=s1.length();
	if (s1.length()!=s2.length()){puts("No");return 0;}
	for (int i=0;i<l;i++){
		if (pa(s1[i])!=pa(s2[i])){puts("No");return 0;}
	}
	puts("Yes");
	return 0;
}