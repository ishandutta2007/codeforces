#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
map<int,map<int,int> >s;
int p[maxn],pos[maxn];
int f(int x,int y) {
	if(s[x][y])return s[x][y];
	cout<<"? "<<x<<' '<<y<<endl;
	cin>>s[x][y];
	s[y][x]=s[x][y];
	return s[x][y];
}
int main() {
	srand(time(0));
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)pos[i]=i;
	for(int i=1;i<=n;i++)swap(pos[rand()%n+1],pos[rand()%n+1]);
	int x=pos[1],y=pos[2],v=f(x,y);
	for(int i=3;i<=n;i++) {
		int v2=f(y,pos[i]);
		if(v2<=v) {
			if(v2==v)y=pos[i],v=f(x,pos[i]);
			else x=pos[i],v=v2;
		}
	}
	int t=(1<<30)-1;
	for(int i=1;i<=20;i++) {
		int z=rand()%n+1;
		if(z==x)continue;
		t&=f(x,z);
	}
	if(t!=0)x=y;
	for(int i=1;i<=n;i++)
		if(x!=i)p[i]=f(x,i);
	printf("!");
	for(int i=1;i<=n;i++)
		printf(" %d",p[i]);
	puts("");
	return 0;
}