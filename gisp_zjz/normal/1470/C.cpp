#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,k,l,r,cc;
int d(int x){
	x=(x%n+n)%n;
	return x+1;
}
int ask(int x){
	++cc;
	printf("? %d\n",d(x));
	fflush(stdout);
	int val; scanf("%d",&val);
	return (val>=k)+(val>k);
}
void ans(int x){
	printf("! %d\n",d(x));
	exit(0);
}
int main(){
    cin >> n >> k;
    if (n<=N){
		for (int i=1;i<=n;i++) ask(0);
		for (int i=0;i<n;i++){
			if (ask(i)==1&&ask(i-1)==0&&ask(i+1)==2) ans(i);
		}
    } else {
        int m=0;
        while (m*m<n) ++m;
        for (int i=1;i<=m;i++) ask(0);
        for (int i=0;i*m<n;i++) if (ask(i*m)==0){
			l=i*m;
			r=i*m+cc+1;
        }
        while (1){
			int mid=(l+r)>>1;
			int op=ask(mid);
			if (op==1){
				ans(mid);
				break;
			} else if (op==0){
				l=mid;
			} else {
				r=mid;
			}
        }
    }
    return 0;
}