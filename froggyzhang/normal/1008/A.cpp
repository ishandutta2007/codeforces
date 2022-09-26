#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
char t[233];
set<char> s;
int main(){
	scanf("%s",t+1);
	n=strlen(t+1);
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('u');
	s.insert('o');
	s.insert('n');
	for(int i=1;i<=n;++i){
		if(s.count(t[i]))continue;
		if(!s.count(t[i+1])||t[i+1]=='n')return !printf("NO\n");
	}
	printf("YES\n");
	return 0;
}