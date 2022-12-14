#include <cstdio>
#include <cstring>
#define MAXN 5010

int n;
int cnt=0;
int p1[MAXN],p2[MAXN];
int a[MAXN],b[MAXN];
int ans[MAXN];

void flush(){ fflush(stdout); }

int ask(int x,int y){
	printf("? %d %d\n",x,y);
	flush();
	int t;
	scanf("%d",&t);
	return t;
}

bool check(int x){
	if(p1[x]!=x) return 0;
	a[0]=x;
	int prev_0=p1[0]^x;
	for(int i=0;i<n;i++)
		a[i]=p2[i]^prev_0;
	memset(b,-1,sizeof b);
	for(int i=0;i<n;i++){
		if(a[i]>=n) return 0;
		if(b[a[i]]!=-1) return 0;
		b[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		if((a[0]^b[i])!=p1[i]) return 0;
		if((a[i]^b[0])!=p2[i]) return 0;
	}
	return 1;
}

void gao(){
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}

int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		p1[i]=ask(0,i);
	for(int i=0;i<n;i++)
		p2[i]=ask(i,0);
	for(int i=0;i<n;i++)
		if(check(i)) cnt++;
	puts("!");
	printf("%d\n",cnt);
	for(int i=0;i<n;i++)
		if(check(i)){
			gao();
			return 0;
		}
	flush();
	return 0;
}