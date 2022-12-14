#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n;
int a[MAXN],b[MAXN];

int main(){
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]==0) b[i]=1;
		if(a[i]<0) cnt++;
	}
	if(cnt&1){
		int x=0;
		a[0]=-1000000001;
		for(int i=1;i<=n;i++)
			if(a[i]<0 && a[i]>a[x])
				x=i;
		b[x]=1;
	}
	int l1=0,l2=0;
	for(int i=1;i<=n;i++)
		if(!b[i]){
			if(l1) printf("1 %d %d\n",l1,i);
			l1=i;
		}else{
			if(l2) printf("1 %d %d\n",l2,i);
			l2=i;
		}
	if(l2 && l1) printf("2 %d\n",l2);
}