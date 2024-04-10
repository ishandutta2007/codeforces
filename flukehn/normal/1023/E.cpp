#include<bits/stdc++.h>
using namespace std;
typedef long long L;
const int N=2e5+11;
char s[N],t[N],ss[N];
int n,x,y;

bool q1(int x,int y){
	printf("? 1 1 %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",ss);
	return ss[0]=='Y';
}
bool q2(int x,int y){
	printf("? %d %d %d %d\n",x,y,n,n);
	fflush(stdout);
	scanf("%s",ss);
	return ss[0]=='Y';
}
bool qq(int x,int y){
	return q1(x,y)&&q2(x,y);
}
int main(){
#ifdef flukehn
	//freopen("g.in","r",stdin);
#endif
	scanf("%d",&n);
	int i,j,w,z;
	for(i=1,j=n;i<=n;++i,--j)
	{
		if(qq(i,j))
			break;
	}
	w=1,z=1;
	while(z<j)
		if(q2(w,z+1))
			s[++x]='R',++z;
		else
			s[++x]='D',++w;
	while(w<i)
		s[++x]='D',++w;
	w=n,z=n;
	while(w>i)
		if(q1(w-1,z))
			t[++y]='D',--w;
		else
			t[++y]='R',--z;
	while(z>j)
		t[++y]='R',--z;
	reverse(t+1,t+y+1);
	printf("! %s%s\n",s+1,t+1);
	fflush(stdout);
}