#include<bits/stdc++.h>
using namespace std;
map<int,map<int,int> >l;
char s[200010];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%s",&n,s+1);//kjhvbjkn
		l.clear();
		int x=0,y=0,L=0,R=0,Min=1e9;
		l[0][0]=1;
		for(int i=1;i<=n;i++) {
			if(s[i]=='L')x--;
			if(s[i]=='R')x++;
			if(s[i]=='U')y--;
			if(s[i]=='D')y++;
			if(l[x][y]) {
				int t=i-l[x][y];
				if(t<Min)Min=t,L=l[x][y],R=i;
			}
			l[x][y]=i+1;
		}
		if(Min<=n)printf("%d %d\n",L,R);
		else puts("-1");
	}
	return 0;
}