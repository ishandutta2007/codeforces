#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
char s[N];
void work(int n){
	if(n<26){
		for(int i=0;i<n;++i)s[i]='a'+i;
		return;
	}
	if(n%2){
		s[n-1]='z';
		--n;
	}
	if(n/2 % 2==0) {
		s[n-1]='y';
		s[n-2]='x';
		n-=2;
	}
	int m=n/4-1;
	for(int i=0;i<m;++i){
		s[i]='a';
		s[i+m+1]='b';
	}
	for(int i=0;i<=m;++i){
		s[2*m+2+i]='a';
		s[3*m+4+i]='b';
	}
	s[m]='c';
	s[2*m+1]='d';
	s[3*m+3]='e';
	s[4*m+5]='f';
}
int main(){
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		work(n);
		s[n]=0;
		puts(s);
	}
}