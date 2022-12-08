#include<bits/stdc++.h>
using namespace std;
int now[10];
void nxt(const char s[]) {
	cout<<"next "<<s<<endl;
	int t;
	cin>>t;
	char S[10];
	for(int i=1;i<=t;i++) {
		cin>>S;
		int n=strlen(S);
		for(int j=0;j<n;j++)
			now[S[j]-'0']=i;
	}
}
signed main() {
	while(1) {
		nxt("0");
		nxt("0 1");
		if(now[0]==now[1])break;
	}
	while(1) {
		nxt("0 1 2 3 4 5 6 7 8 9");
		if(now[0]==now[9])break;
	}
	puts("done");
	return 0;
}