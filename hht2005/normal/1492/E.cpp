#include<bits/stdc++.h>
using namespace std;
const int maxn=2.5e5+10;
vector<int>s[maxn];
int t[maxn],n,m,b[5];
void yes() {
	puts("Yes");
	for(int i=1;i<=m;i++)
		printf("%d ",t[i]);
	puts("");
	exit(0);
}
void no() {
	puts("No");
	exit(0);
}
int check() {
	for(int i=1;i<=n;i++) {
		int k=0;
		for(int j=1;j<=m;j++)
			if(t[j]!=s[i][j])k++;
		if(k>2)return 0;
	}
	return 1;
}
int check(int p) {
	for(int i=1;i<=n;i++) {
		int k=0;
		for(int j=1;j<=m;j++)
			if(t[j]!=s[i][j])k++;
		if(k>3)return 0;
		if(k==3) {
			if(t[p]!=s[i][p]) {
				if(!t[p])t[p]=s[i][p];
				else return 0;
			} else return 0;
		}
	}
	return 1;
}
int main() {
	int a,c1=-1,c2=-1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		s[i].push_back(0);
		for(int j=1;j<=m;j++) {
			scanf("%d",&a);
			s[i].push_back(a);
		}
	}
	for(int i=1;i<=m;i++)
		t[i]=s[1][i];
	for(int i=2;i<=n;i++) {
		int k=0;
		for(int j=1;j<=m;j++)
			if(t[j]!=s[i][j])k++;
		if(k>4)no();
		if(c2<k) {
			c1=i;
			c2=k;
		}
	}
	cerr<<c1<<endl;
	if(c2<=2)yes();
	if(c2==3) {
		int cnt=0;
		for(int i=1;i<=m;i++)
			if(t[i]!=s[c1][i])
				b[++cnt]=i;
		for(int j=1;j<=3;j++)
			for(int k=0;k<=3;k++) {
				if(j==k)continue;
				t[b[j]]=s[c1][b[j]];
				t[b[k]]=0;
				if(check(b[k]))yes();
				t[b[k]]=s[1][b[k]];
				t[b[j]]=s[1][b[j]];
			}
		no();
	} else if(c2==4) {
		int cnt=0;
		for(int i=1;i<=m;i++)
			if(t[i]!=s[c1][i])
				b[++cnt]=i;
		for(int j=1;j<4;j++)
			for(int k=j+1;k<=4;k++) {
				t[b[j]]=s[c1][b[j]];
				t[b[k]]=s[c1][b[k]];
				if(check())yes();
				t[b[j]]=s[1][b[j]];
				t[b[k]]=s[1][b[k]];
			}
		no();
	}
	return 0;
}