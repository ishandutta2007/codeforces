#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
int n,k;
#define cout cerr

int ask(int x){
	printf("? %d\n",x+1);fflush(stdout);
	int y;scanf("%d",&y);return y;
}

int main(){
	scanf("%d%d",&n,&k);
	int pos=n-1;ask(pos);int x=ask(pos-1);
	if(x!=k){printf("! %d\n",x<k?pos+1:pos-1);fflush(stdout);return 0;}
	pos--;
	for(int i=2;;++i){
		pos=(pos-(i-1)+n)%n;x=ask(pos);
		if(x!=k){
			if(i==2&&x<k){printf("! %d\n",(pos+1)%n+1);fflush(stdout);return 0;}
			do{
				pos=(pos-1+n)%n;
			}while(ask(pos)!=k);
			printf("! %d\n",pos+1); fflush(stdout); return 0;
		}
	}
	return 0;
}