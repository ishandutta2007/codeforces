#include<bits/stdc++.h>
using namespace std;
const int N=1<<19;
int t[N];
int rand_d(int l,int r) {
	return (rand()*(RAND_MAX+1ll)+rand())%(r-l+1)+l;
}
int main() {
	int h,n;
	cin>>h;
	n=(1<<h)-1;
	for(int i=1;i<=420;i++) {
		int x=rand_d(1,n),y=rand_d(1,n),z=rand_d(1,n);
		if(x==y||x==z||y==z) {
			i--;
			continue;
		}
		printf("? %d %d %d\n",x,y,z);
		fflush(stdout);
		scanf("%d",&x);
		t[x]++;
	}
	int Max[2]={0,0},x;
	for(int i=1;i<=n;i++) {
		int I=i;
		if(t[Max[0]]<t[I])swap(Max[0],I);
		if(t[Max[1]]<t[I])swap(Max[1],I);
	}
	for(int i=1;i<=n;i++) {
		if(i==Max[0]||i==Max[1])continue;
		printf("? %d %d %d\n",Max[0],Max[1],i);
		fflush(stdout);
		cin>>x;
		if(x==i) {
			printf("! %d\n",i);
			break;
		}
	}
	return 0;
}