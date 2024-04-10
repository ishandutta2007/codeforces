#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,m;
int a[MAXN],b[MAXN];
int ans[MAXN][3],cnt;

void output(int res){
	if(!res) puts("NO");
	else{
		puts("YES");
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
	exit(0);
}

void flip(int x,int y,int z){
	ans[++cnt][0]=x;
	ans[cnt][1]=y;
	ans[cnt][2]=z;
	sort(ans[cnt],ans[cnt]+3);
	a[x]^=1; a[y]^=1; a[z]^=1;
}

void flip2(int l,int r){ flip(l,(l+r)/2,r); }

void gao(int x){
	if(n<7) output(0);
	if(n==7 && x!=1 && x!=4 && x!=7) output(0);
	if(x==1) flip(1,2,3),flip(2,3,4),gao(4);
	else if(x==2) flip(2,3,4),flip(3,4,5),gao(5);
	else if(x==3) flip(3,4,5),gao(4),gao(5);
	else if(x==n) flip(n,n-1,n-2),flip(n-1,n-2,n-3),gao(n-3);
	else if(x==n-1) flip(n-1,n-2,n-3),flip(n-2,n-3,n-4),gao(n-4);
	else if(x==n-2) flip(n-2,n-3,n-4),gao(n-3),gao(n-4);
	else{
		flip(x-3,x,x+3);
		flip(x-3,x-1,x+1);
		flip(x-1,x+1,x+3);
	}
}
 
int main(){
#ifdef DEBUG
	freopen("C.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	int l=1,r=n;
	while(r-l+1>7){
		if(!a[l]) l++;
		else if(!a[r]) r--;
		else if(a[l+1] && a[l+2]) flip(l,l+1,l+2);
		else if(!a[l+1] && a[l+2]) flip(l,l+2,l+4);
		else if(!a[l+1] && !a[l+2]) flip(l,l+3,l+6);
		else if(a[r-1] && a[r-2]) flip(r,r-1,r-2);
		else if(!a[r-1] && a[r-2]) flip(r,r-2,r-4);
		else if(!a[r-1] && !a[r-2]) flip(r,r-3,r-6);
		else if((r-l)%2==0) flip2(l,r),flip2(l+1,r-1);
		else flip2(l,r-1),flip2(l+1,r);
	}
	while(r-l+1>=3){
		if(a[l]) flip(l,l+1,l+2);
		l++;
	}
	if(!a[l] && !a[r]) output(1);
	else if(!a[l]) gao(r);
	else if(!a[r]) gao(l);
	else if(l>1) flip(l-1,l,l+1),gao(l-1);
	else if(r<n) flip(r-1,r,r+1),gao(r+1);
	else output(0);
	output(1);
}